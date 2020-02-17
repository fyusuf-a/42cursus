<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wordpress' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */define('AUTH_KEY',         ',37NGvcwRKx/TJm`Ph^ B?0eO|5u^=em__+E+:%?>190`,`UAWXkxq=yl2v{D<{J');
define('SECURE_AUTH_KEY',  'CK3[^&mdsV&4-.0VfJCq:26g0a{c%p?oS],+x-,0)Z3TDX{$}_s|&4>MZ40KJ|ZN');
define('LOGGED_IN_KEY',    'U  =-Em)4k:AYRmQ}4F,R(Ppi3?6zDNrJB&z:i,9JT!wWhh|Vr=eTY?N@aDEEsY?');
define('NONCE_KEY',        '?L/V`r-;U+?`bqEBZi$z5VNvMd{sToS5{0qcq4~_t1Ym4-|!4,DF=XOfO}!zSfOr');
define('AUTH_SALT',        '}B=C1!$5+3zVrj&euS23YXS!-.<D@:5BH5?@st6r/b-Lod_JP7P,qQo+8M{hLUHF');
define('SECURE_AUTH_SALT', '+_+^ZQ/P&+Vuy!3=+rpF:!1L,|iw|o[7-Mn_}cf6FfbvtWLHU@GfRfwsCQ GreEd');
define('LOGGED_IN_SALT',   '_S~ 0?L0POt;(@c7WNd`GJ0`S`EmO-|:moXW7Ps{,W@[SvFda|juZ^Ghx,qzOu+X');
define('NONCE_SALT',       '4/kq1l;#sde@DYq{UAMTD)+/07d1>Fry7q&+Kd*5$z[R*Zs>||nd*lGlO3{]1>Y<');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
