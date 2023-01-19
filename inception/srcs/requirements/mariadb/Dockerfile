FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install mariadb-server
RUN apt-get -y install procps

COPY conf/mysql_file.cnf /etc/mysql/mariadb.conf.d/
#https://help.nextcloud.com/t/configuring-mariadb-database-when-using-docker/137449
COPY conf/start.sh /tmp/

RUN mkdir -p /run/mysqld && chown -R mysql:root /run/mysqld && chown -R mysql:mysql /var/lib/mysql

ENTRYPOINT ["bash", "tmp/start.sh"]

CMD ["mysqld"]

#https://devtron.ai/blog/cmd-and-entrypoint-differences/#:~:text=CMD%3A%20Sets%20default%20parameters%20that,Docker%20Containers%20with%20CLI%20parameters.