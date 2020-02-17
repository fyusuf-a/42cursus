CREATE DATABASE wordpress;
CREATE USER wordpress@localhost IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON wordpress.* TO wordpress@localhost;
