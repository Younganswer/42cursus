#!/bin/bash

service mysql start 

echo "CREATE DATABASE IF NOT EXISTS $db_name ;" > mariadb.sql
echo "CREATE USER IF NOT EXISTS '$db_user'@'%' IDENTIFIED BY '$db_pwd' ;" >> mariadb.sql
echo "GRANT ALL PRIVILEGES ON $db_name.* TO '$db_user'@'%' ;" >> mariadb.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY 'p@55w0rd' ;" >> mariadb.sql
echo "FLUSH PRIVILEGES;" >> mariadb.sql

mysql < mariadb.sql

kill $(cat /var/run/mysqld/mysqld.pid)

mysqld