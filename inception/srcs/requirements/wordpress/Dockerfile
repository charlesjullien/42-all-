FROM debian:buster

RUN apt-get -y update && apt-get -y install wget && apt-get -y install mariadb-client && apt-get -y install php7.3-fpm php7.3-common php7.3-mysql
RUN apt-get -y install procps

COPY conf/start.sh /tmp/
COPY conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && cp wp-cli.phar /usr/bin/wp && mkdir -p /var/run/php/

WORKDIR /var/www/html/wordpress
#The WORKDIR instruction sets the working directory for any RUN, CMD, ENTRYPOINT, COPY and ADD instructions that follow it in the Dockerfile. If the WORKDIR doesn’t exist, it will be created even if it’s not used in any subsequent Dockerfile instruction.
#https://docs.docker.com/engine/reference/builder/#workdir

ENTRYPOINT ["bash", "/tmp/start.sh"]

CMD ["php-fpm7.3", "-F", "-R"]

# -F : force to stay in foreground, and ignore daemonize option from config file
# -R : Allow pool to run as root (disabled by default). To make it pid 1

