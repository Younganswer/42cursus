#!/bin/bash

# create directory to use in nginx container later and also to setup the wordpress conf
mkdir /var/www/
mkdir /var/www/html

cd /var/www/html

rm -rf *

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 

chmod +x wp-cli.phar 

mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root

rm wp-config-sample.php
mv /wp-config.php .

sed -i "0,/'db'/s//'$db_name'/1"    wp-config.php
sed -i "0,/'user'/s//'$db_user'/1"  wp-config.php
sed -i "0,/'pwd'/s//'$db_pwd'/1"    wp-config.php


wp core install --url=$DOMAIN_NAME/ --title=$WP_TITLE --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root

wp user create $WP_USR $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root

wp theme install astra --activate --allow-root

wp plugin install redis-cache --activate --allow-root

wp plugin update --all --allow-root

sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' /etc/php/7.3/fpm/pool.d/www.conf
sed -i 's/127.0.0.1/0.0.0.0:9000/g' /etc/php/7.3/fpm/pool.d/www.conf

mkdir /run/php

wp redis enable --allow-root

/usr/sbin/php-fpm7.3 -F