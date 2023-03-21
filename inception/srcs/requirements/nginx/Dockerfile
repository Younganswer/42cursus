FROM debian:buster

RUN apt-get update && apt-get install -y
RUN apt-get install -y nginx && apt-get install -y openssl

COPY ./conf/default /etc/nginx/sites-available/default

CMD [ "./tools/script.sh" ]