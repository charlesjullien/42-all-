#!/bin/bash

wp core download --allow-root
wp config create --dbname=wordpress --dbuser=$LOGIN --dbpass=$PASSWORD --dbhost=mariadb --dbcollate="utf8_general_ci" --allow-root 
#Downloads core WP files + https://www.devfaq.fr/question/allow-root-ne-fonctionne-pas-en-ex-eacute-cutant-wp-cli-dans-le-conteneur-docker + https://github.com/wp-cli/wp-cli/issues/4548#issue-278813629
# && : config creates generates a wp-config.php file https://developer.wordpress.org/cli/commands/config/create/

wp core install --url=$SITE_URL/wordpress --title=testsite --admin_user=$LOGIN --admin_password=$PASSWORD --admin_email=$EMAIL --skip-email --allow-root
#https://developer.wordpress.org/cli/commands/core/install/

wp user create $GUEST_LOGIN $GUEST_EMAIL --user_pass=$GUEST_PASSWORD --role=subscriber --allow-root
#https://developer.wordpress.org/cli/commands/user/create/

exec "$@"