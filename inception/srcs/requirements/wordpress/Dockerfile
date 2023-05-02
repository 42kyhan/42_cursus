FROM alpine:3.15

RUN apk update && \
    apk add curl mariadb-client php7 php7-fpm php7-phar php7-json php7-curl php7-mysqli php7-mbstring && \
    apk add openrc && openrc && touch run/openrc/softlevel && \
    apk add wget && \
    mkdir -p /var/www/wordpress && \
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    cp wp-cli.phar /usr/bin/wp && \
    wget -O /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/local/bin/dumb-init

COPY conf/wp-config.php /tmp/wp-config.php
COPY tools/script.sh /tmp/script.sh

RUN chmod +x /tmp/script.sh 
WORKDIR /var/www/wordpress

ENTRYPOINT ["/usr/local/bin/dumb-init", "--"]
CMD ["sh", "-c", "/tmp/script.sh"]
