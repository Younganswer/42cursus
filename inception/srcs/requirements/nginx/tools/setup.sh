#!/bin/bash

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out $CERTS_ -subj "/C=MO/L=KH/O=1337/OU=student/CN=younhwan.42.fr"

sed -i "5d" /etc/nginx/sites-available/default
sed -i "5i\ \   server_name www.$DOMAIN_NAME $DOMAIN_NAME;" /etc/nginx/sites-available/default

sed -i "7d" /etc/nginx/sites-available/default
sed -i "7i\ \   ssl_certificate $CERTS_;" /etc/nginx/sites-available/default

nginx -g "daemon off;"