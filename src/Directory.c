#include "Directory.h"


/*----------------------------------------------*
 * 宏定义                                 *
 *----------------------------------------------*/
#ifdef	PATH_MAX
static long	pathmax = PATH_MAX;
#else
static long	pathmax = 0;
#endif

static long	posix_version = 0;
static long	xsi_version = 0;
/*----------------------------------------------*
 * 局部变量                                 *
 *----------------------------------------------*/



/**
*@brief 针对目录分配所需空间
*
*
*@param size_t *sizep
*
*@return char *
* 
*
*@author Litost_Cheng
*@date 2019年1月12日
*@note 新生成函数

*/
char * DirPathBufAlloc(size_t *sizep) /* also return allocated size, if nonnull */
{
	char	*ptr;
	size_t	size;

	if (posix_version == 0)
		posix_version = sysconf(_SC_VERSION);

	if (xsi_version == 0)
		xsi_version = sysconf(_SC_XOPEN_VERSION);

	if (pathmax == 0) {		/* first time through */
		errno = 0;
		if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
			if (errno == 0)
				pathmax = PATH_MAX_GUESS;	/* it's indeterminate */
			else
				ErrSys("pathconf error for _PC_PATH_MAX");
		} else {
			pathmax++;		/* add one since it's relative to root */
		}
	}

	/*
	 * Before POSIX.1-2001, we aren't guaranteed that PATH_MAX includes
	 * the terminating null byte.  Same goes for XPG3.
	 */
	if ((posix_version < 200112L) && (xsi_version < 4))
		size = pathmax + 1;
	else
		size = pathmax;

	if ((ptr = malloc(size)) == NULL)
		ErrSys("malloc error for pathname");

	if (sizep != NULL)
		*sizep = size;
	return(ptr);
}
