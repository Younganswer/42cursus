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
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'db' );

/** MySQL database username */
define( 'DB_USER', 'user' );

/** MySQL database password */
define( 'DB_PASSWORD', 'pwd' );

/** MySQL hostname */
define( 'DB_HOST', 'mariadb' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define( 'WP_ALLOW_REPAIR', true );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '`a5gi_JB.U[k?fdJ]GFI/9QgX_bu]&RBy|FEmwa[A:srT0F9J`&E!#sEB#+-zpQ#' );
define( 'SECURE_AUTH_KEY',  ')3v>|zZvj^-*MQC{H9ttyU4hFgh>f9A.b&J}tMb:F#$&A@dz?*ChyD# UJZ*ZdD)' );
define( 'LOGGED_IN_KEY',    'e*mHMzcbe+0gczlB<F,If`&g#^dZs8~@)Xm5#He@OwH!%|?M=A-%|8%SGK|J-sM*' );
define( 'NONCE_KEY',        '}TX.^$y:3|8P]7<QM@bE:[{JA!pT+_wEkWz;qL.@8mGXG+TKdT]df|=NV1+z]|?{' );
define( 'AUTH_SALT',        '!7giapTY-&QZgWN=bd6f0nT%b%>MH2B%tH|).{])~C6BDx~~rTK>(G3l;_]ngf_:' );
define( 'SECURE_AUTH_SALT', 'Mm_RtT?~8dC<OERh]bF-KNwhn6[5 Id20+K=O+cFs0U(GNKuap-?OU%]*F?FpIs@' );
define( 'LOGGED_IN_SALT',   'B+Gl+{>w-w?h-~$!D[gGR*.hT+~r<}GX7Fu+Gbh.tuY%A_B`%{n-^_-UCAi?!jd<' );
define( 'NONCE_SALT',       '[=B9 Z|i0^}w0=VEp .+fbctVv~rt8Z`bD|sCJ<~WiPZ.]W=6Gl?jmQ{x9X{Z<7}' );

define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_REDIS_PORT', 6379 );

define( 'WP_CACHE', true );

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
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
?>