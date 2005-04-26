/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:  Alan Knowles <alan@akbkhome.com>                            |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_SVN_H
#define PHP_SVN_H

extern zend_module_entry svn_module_entry;
#define phpext_svn_ptr &svn_module_entry

#ifdef PHP_WIN32
#define PHP_SVN_API __declspec(dllexport)
#else
#define PHP_SVN_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif
#include "svn_client.h"

PHP_MINIT_FUNCTION(svn);
PHP_MSHUTDOWN_FUNCTION(svn);
PHP_RINIT_FUNCTION(svn);
PHP_RSHUTDOWN_FUNCTION(svn);
PHP_MINFO_FUNCTION(svn);

PHP_FUNCTION(confirm_svn_compiled);	/* For testing, remove later. */
PHP_FUNCTION(svn_checkout);
PHP_FUNCTION(svn_cat);
PHP_FUNCTION(svn_ls);
PHP_FUNCTION(svn_log);
/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     
*/
ZEND_BEGIN_MODULE_GLOBALS(svn)
	apr_pool_t *pool;
	svn_client_ctx_t *ctx;
ZEND_END_MODULE_GLOBALS(svn)
 

/* In every utility function you add that needs to use variables 
   in php_svn_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as SVN_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define SVN_G(v) TSRMG(svn_globals_id, zend_svn_globals *, v)
#else
#define SVN_G(v) (svn_globals.v)
#endif

#endif	/* PHP_SVN_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
