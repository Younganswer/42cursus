FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install mariadb-server -y

COPY ./conf/50-server.conf /etc/mysql/mariadb.conf.d/
COPY ./tools/setup.sh /

RUN chmod +x /setup.sh

CMD ["/setup.sh"]