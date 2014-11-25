#include "libngx.h"

size_t ngx_pagesize = 4096;

void ngx_init_pagesize(size_t size)
{
	ngx_pagesize = size;
	return;
}