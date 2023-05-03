cp /tmp/nginx.conf /etc/nginx/http.d/default.conf

exec nginx -g 'daemon off;'