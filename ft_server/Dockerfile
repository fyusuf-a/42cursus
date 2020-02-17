FROM debian:buster-slim

ARG ROOT_DIR=/var/www/html
ARG AUTOINDEX=on

RUN apt-get update; \
		apt-get install -y nginx php-fpm mariadb-server php7.3-mysql php7.3-mbstring curl unzip

# nginx
RUN rm /etc/nginx/sites-enabled/default /var/www/html/index.nginx-debian.html
RUN ln -sf /dev/stdout /var/log/nginx/access.log ;\
		ln -sf /dev/stderr /var/log/nginx/error.log
COPY srcs/index.php /var/www/html/index.php

# mariadb
COPY srcs/create.sql /
RUN service mysql start && \
		mysql < create.sql && \
		rm create.sql

# wordpress
RUN curl -L https://wordpress.org/latest.tar.gz | tar -xz -C /var/www/html
COPY srcs/wordpress.conf /etc/nginx/sites-available/wordpress.conf
RUN sed -i 's+%ROOT_DIR%+'$ROOT_DIR'+g' /etc/nginx/sites-available/wordpress.conf ; \
		sed -i 's/%AUTOINDEX%/'$AUTOINDEX'/g' /etc/nginx/sites-available/wordpress.conf ; \
		ln -s /etc/nginx/sites-available/wordpress.conf /etc/nginx/sites-enabled/wordpress.conf ; \
		rm /var/www/html/wordpress/wp-config-sample.php
COPY srcs/wp-config.php /var/www/html/wordpress/

# phpmyadmin
RUN curl -lO https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-all-languages.zip && \
 		unzip -qq phpMyAdmin-5.0.1-all-languages.zip -d /var/www/html/ && \
		rm phpMyAdmin-5.0.1-all-languages.zip && \
		mv /var/www/html/phpMyAdmin-5.0.1-all-languages /var/www/html/phpmyadmin

# SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/ssl-cert-snakeoil.key -out /etc/ssl/certs/ssl-cert-snakeoil.pem -subj '/CN=localhost'

EXPOSE 80

CMD service php7.3-fpm start && \
		service mysql start && \
		service nginx start && \
		/bin/bash
