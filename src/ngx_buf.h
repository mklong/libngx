
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_BUF_H_INCLUDED_
#define _NGX_BUF_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include "libngx.h"


typedef void *            ngx_buf_tag_t;

typedef struct ngx_buf_s  ngx_buf_t;

struct ngx_buf_s {
    u_char          *pos;
    u_char          *last;
 
    u_char          *start;         /* start of buffer */
    u_char          *end;           /* end of buffer */
  
};

struct ngx_chain_s {
    ngx_buf_t    *buf;
    ngx_chain_t  *next;
};

typedef struct {
    ngx_int_t    num;
    size_t       size;
} ngx_bufs_t;





#define NGX_CHAIN_ERROR     (ngx_chain_t *) NGX_ERROR



#define ngx_buf_size(b)       (off_t) (b->last - b->pos)

ngx_buf_t *ngx_create_temp_buf(ngx_pool_t *pool, size_t size);
ngx_chain_t *ngx_create_chain_of_bufs(ngx_pool_t *pool, ngx_bufs_t *bufs);

#define ngx_alloc_buf(pool)  (ngx_buf_t*)ngx_palloc(pool, sizeof(ngx_buf_t))
#define ngx_calloc_buf(pool) (ngx_buf_t*)ngx_pcalloc(pool, sizeof(ngx_buf_t))

ngx_chain_t *ngx_alloc_chain_link(ngx_pool_t *pool);
#define ngx_free_chain(pool, cl)                                             \
    cl->next = pool->chain;                                                  \
    pool->chain = cl

ngx_int_t ngx_chain_add_copy(ngx_pool_t *pool, ngx_chain_t **chain,
    ngx_chain_t *in);
ngx_chain_t *ngx_chain_get_free_buf(ngx_pool_t *p, ngx_chain_t **free);


#ifdef __cplusplus
}
#endif


#endif /* _NGX_BUF_H_INCLUDED_ */
