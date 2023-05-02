#!/bin/sh

sed -i "s/listen = 127.0.0.1:9000/listen = wordpress:9000/" /etc/php7/php-fpm.d/www.conf
sed -i "s/;clear_env = no/clear_env = no/" /etc/php7/php-fpm.d/www.conf

if [ ! -f "/var/www/wordpress/wp-config.php" ]; then

cp /tmp/wp-config.php /var/www/wordpress/wp-config.php
wp core download --allow-root
wp core install --url=$WORDPRESS_DOMAIN_NAME --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PWD --admin_email=$WORDPRESS_ADMIN_EMAIL --skip-email --allow-root
wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=author --user_pass=$WORDPRESS_USER_PWD --allow-root

fi

/usr/sbin/php-fpm7 -F -R
