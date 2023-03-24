<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'WordPress' );

/** Database username */
define( 'DB_USER', 'younhwan' );

/** Database password */
define( 'DB_PASSWORD', 'younhwan' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '6;6NFk&bYMykQ?+7+>YP)jHA=UCYjUhZN0Tt,&AQ2:BN;Kom+C;O=su)[{hw$pU,');
define('SECURE_AUTH_KEY',  '-.@;xKoJI~ 5>Wf*%QWw!/D iav2ViZ~j.4&#|(55j9Hs%+<^Ofg|uLKAEMT` co');
define('LOGGED_IN_KEY',    'I[p4(^.]4w[*.%[qi53,-dedL*+mZw:/[]Ff-+$tor]$/JPlD(!sYItw&Q@EE vi');
define('NONCE_KEY',        'Im;/m]bu5,i|djTVmNBzLtpM_ep;yk5f6K8Ktm2R|M#y4_Gr>r|B b%41QA%~UZp');
define('AUTH_SALT',        '`mqHw;nr.*)UWWT_buWp%~<WDI)>*4+hdFtGS}1nV~_m?/Hr|@5=M*|n]AS3Q.r#');
define('SECURE_AUTH_SALT', '4IzWIVIVD_QI9J^1snKzK>ro4*6~?I>N4<5RbRhvbt$M:_qk E)(|iL`zCnrM=yM');
define('LOGGED_IN_SALT',   '?U~89fV`^_-w^[[B!BQm)8iLQilhXa|!v5CF!J-1(L`R^#T)PZ(zs%z, q;(+zyH');
define('NONCE_SALT',       'zUxo.XqpcIm<wpafC@u]|UpEuoNJVU<+>kr}lL7Us[xq7$I6k}`E538-G9dh0vrJ');

/**#@-*/

/**
 * WordPress database table prefix.
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
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
