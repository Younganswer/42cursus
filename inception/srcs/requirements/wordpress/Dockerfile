FROM debian:buster

LABEL	name="wordpress" \
		version="1.0" \
		description="wordpress"

EXPOSE 9000

RUN apt update -y
RUN apt install php-fpm php-mysql curl -y

COPY ./tools/setup.sh /

RUN chmod +x /setup.sh

CMD ["/setup.sh"]