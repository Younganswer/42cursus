FROM debian:buster

LABEL	name="mariadb" \
		version="1.0" \
		description="mariadb"

EXPOSE 3306

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install mariadb-server -y

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/setup.sh /

RUN chmod +x /setup.sh

CMD ["/setup.sh"]