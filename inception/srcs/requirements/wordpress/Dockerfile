FROM debian:buster

RUN apt update -y
RUN apt install php-fpm php-mysql curl -y

COPY ./tools/setup.sh /
COPY ./conf/wp-config.php /var/www/html/wp-config.php

RUN chmod +x /setup.sh

CMD ["/setup.sh"]