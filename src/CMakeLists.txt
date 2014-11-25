
set(LIB_SRC
  ngx_string.c
  ngx_rbtree.c
  ngx_radix_tree.c
  ngx_queue.c
  ngx_palloc.c
  ngx_palloc.c
  ngx_hash.c
  ngx_buf.c
  ngx_array.c
  libngx.c
  )

include_directories(./)

add_library(ngx STATIC ${LIB_SRC})
