FROM php:7-apache

RUN apt-get update
RUN apt-get install -y htop vim

RUN apt-get update \
  && echo 'deb http://packages.dotdeb.org jessie all' >> /etc/apt/sources.list \
  && echo 'deb-src http://packages.dotdeb.org jessie all' >> /etc/apt/sources.list \
  && apt-get install -y wget \
  && wget https://www.dotdeb.org/dotdeb.gpg \
  && apt-key add dotdeb.gpg \
  && apt-get update \
  && apt-get install -y php7.0-mysql \
  && docker-php-ext-install pdo_mysql

COPY php-code /var/www/html
