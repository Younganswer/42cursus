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
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'younhwan' );

/** MySQL database password */
define( 'DB_PASSWORD', 'younhwan' );

/** MySQL hostname */
define( 'DB_HOST', 'mariadb' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

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
define( 'AUTH_KEY',         'c;-N[ZqHs4 G^2_aywC*ez+P-xi]`+VZ/!K!w@#u+#Jz5f,{w>9D6UD,1UOvm8MB' );
define( 'SECURE_AUTH_KEY',  'XF4)a^Q$f6Fgwu#.U]aHdc5:Tpob v&MiIz=vNls$riA.jmk2e5g%k,luTR)Zo*%' );
define( 'LOGGED_IN_KEY',    'bbk9KI=a;!K`@y+1_f|xab1!jn[KKV6kf+%vA?b7&%A:Ya`vaX{%1iU|cQ_l,31M' );
define( 'NONCE_KEY',        'MIm3Prx@29:cUB2r-w?tiq)y:0MN=(jaV,8U#Yiq~IGN[&^ml8HImo;v)d7#(RX5' );
define( 'AUTH_SALT',        '+S+[`,VNoCtmx/,+l$nf7LH<ZNkPey^RtOe~c#<&DHd*e-cI=G1r]hrcT>.&ZVqs' );
define( 'SECURE_AUTH_SALT', 'ejH*CRq=+Mva`+~^+s[S;+OUbX Hbo{+V_o_{Qnx/d>i_MICp5!WRsNhO~4G1K=8' );
define( 'LOGGED_IN_SALT',   '8Mr2-$M`5GMJa6TMvolooLqDBsx.&EkFY]dB{(>2V?GTOiEa09*~v;|l^.Hcx{,5' );
define( 'NONCE_SALT',       'JT];:l{ci@C+~+M3s}lS~G>Q!VdyFt]or<kGC#z?MCF<k(H.sOlyt=,#/K3rdL^1' );

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