FROM alpine:3.15

RUN apk update && \
    apk add nginx && \
    apk add openssl && \
    openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42/CN=localhost" -keyout /etc/ssl/certs/kyhan.42.fr.key -out /etc/ssl/certs/kyhan.42.fr.crt && \
    wget -O /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/local/bin/dumb-init 

COPY conf/nginx.conf /tmp/nginx.conf
COPY tools/script.sh /tmp/script.sh

RUN chmod +x /tmp/script.sh

EXPOSE 443

# dumb-init as your container's entrypoint
ENTRYPOINT ["/usr/local/bin/dumb-init", "--"]
CMD ["sh", "-c", "/tmp/script.sh"]
