FROM alpine:3.15

RUN apk update && \
    apk add mariadb && \
    apk add mariadb-client && \
    mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld && \
    wget -O /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/local/bin/dumb-init 

COPY conf/maria.sql /tmp/maria.sql
COPY tools/script.sh /tmp/script.sh

RUN chmod +x /tmp/script.sh

ENTRYPOINT ["/usr/local/bin/dumb-init", "--"]
CMD ["sh", "-c", "/tmp/script.sh"]