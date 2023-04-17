FROM debian:buster

RUN apt-get update && apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 356 -nodes -out /etc/nginx/ssl/kyhan.crt -keyout /etc/nginx/ssl/kyhan.key -subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=kyhan/CN=kyhan/"

COPY ./conf/nginx.conf /etc/nginx/conf.d

RUN mkdir -p run/nginx

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]