FROM debian:buster

LABEL	name="nginx" \
		version="1.0" \
		description="nginx"

RUN apt-get update && apt-get install -y
RUN apt-get install -y nginx && apt-get install -y openssl

COPY ./conf/default /etc/nginx/sites-available/default
COPY ./tools/setup.sh /setup.sh

RUN chmod +x /setup.sh

CMD [ "/setup.sh" ]