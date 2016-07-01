#!/usr/bin/env bash
# Installs drupal site.

echo "Installing drupal site."
pushd /var/www/pwcdevtest
drush si -y --account-name=pwcdevtest --account-pass=pwcdevtest --locale=uk --db-url=mysql://pwcdevtest:pwcdevtest@localhost/pwcdevtest --site-name="PwC dev test"
drush en -y enabled_module
drush st
popd
