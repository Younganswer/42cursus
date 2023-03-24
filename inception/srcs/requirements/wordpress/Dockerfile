FROM debian:buster

LABEL	name="wordpress" \
		version="1.0" \
		description="wordpress"

EXPOSE 9000

RUN apt update -y
RUN apt install php7.3 php-cli php-fpm php-mysql curl -y
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/setup.sh /

RUN chmod +x /setup.sh

CMD ["/setup.sh"]