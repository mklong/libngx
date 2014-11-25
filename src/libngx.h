/** 
* @file	libngx.h
* @brief	
*		based on nginx core (Igor Sysoev Nginx, Inc)
* detail...
*	    nginx core data structure 
*
* @author	mklong
* @version	1.0
* @date	2014/11/17
* 
* @see		
* 
* <b>History:</b><br>
* <table>
*  <tr> <th>Version	<th>Date		<th>Author	<th>Notes</tr>
*  <tr> <td>1.0		<td>2014/11/17	<td>mklong	<td>Create this file</tr>
* </table>
* 
*/
#ifndef __LIBNGX_H__
#define __LIBNGX_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#ifdef WIN32
#include <string.h>
#endif


#ifdef WIN32

#define ngx_cdecl		__cdecl
#define ngx_inline		__inline
#else

#define ngx_cdecl
#define ngx_inline      inline
#endif

#define NGX_MAX_UINT32_VALUE  (uint32_t) 0xffffffff

#define NGX_INT32_LEN   sizeof("-2147483648") - 1
#define NGX_INT64_LEN   sizeof("-9223372036854775808") - 1

//#if (NGX_PTR_SIZE == 4)
#define NGX_INT_T_LEN   NGX_INT32_LEN
//#else
//#define NGX_INT_T_LEN   NGX_INT64_LEN
//#endif

#define ngx_thread_volatile   volatile

//
#define ngx_cacheline_size 64

#ifndef NGX_ALIGNMENT
#define NGX_ALIGNMENT   sizeof(unsigned long)    /* platform word */
#endif

#define ngx_align(d, a)     (((d) + (a - 1)) & ~(a - 1))

#define ngx_align_ptr(p, a)                                                   \
	(u_char *) (((uintptr_t) (p) + ((uintptr_t) a - 1)) & ~((uintptr_t) a - 1))

#define ngx_memcpy(dst, src, n)   (void) memcpy(dst, src, n)
#define ngx_memzero(buf, n)       (void) memset(buf, 0, n)
#define ngx_memset(buf, c, n)     (void) memset(buf, c, n)

#define ngx_abs(value)       (((value) >= 0) ? (value) : - (value))
#define ngx_max(val1, val2)  ((val1 < val2) ? (val2) : (val1))
#define ngx_min(val1, val2)  ((val1 > val2) ? (val2) : (val1))

#define  NGX_OK          0
#define  NGX_ERROR      -1
#define  NGX_AGAIN      -2
#define  NGX_BUSY       -3
#define  NGX_DONE       -4
#define  NGX_DECLINED   -5
#define  NGX_ABORT      -6

#define LF     (u_char) 10
#define CR     (u_char) 13
#define CRLF   "\x0d\x0a"

	//avoid cast
#ifdef NGX_USE_UCHAR
typedef unsigned char		u_char;
#else
typedef char		u_char;
#endif

typedef intptr_t		ngx_int_t;
typedef uintptr_t		ngx_uint_t;
typedef int				ngx_flag_t;
typedef unsigned short	u_short;
typedef unsigned int	u_int;
typedef unsigned long	u_long;


#ifdef WIN32
typedef int	ngx_pid_t;
#else
typedef pid_t	ngx_pid_t;
#endif

#ifdef WIN32
typedef size_t ssize_t;
typedef long off_t;
#endif 

extern size_t ngx_pagesize;

void ngx_init_pagesize(size_t size);

typedef struct ngx_pool_s        ngx_pool_t;
typedef struct ngx_chain_s       ngx_chain_t;

#include "ngx_palloc.h"
#include "ngx_buf.h"
#include "ngx_array.h"
#include "ngx_list.h"
#include "ngx_rbtree.h"
#include "ngx_string.h"
#include "ngx_queue.h"
#include "ngx_radix_tree.h"
#include "ngx_hash.h"

#ifdef __cplusplus
}
#endif

#endif /* __LIBNGX_H__ */
