#include <stdlib.h>
#include "test_utils.h"

int mem_malloc_count = 0;

void* mem_malloc(size_t size)
{
	++mem_malloc_count;
	return malloc(size);
}

void mem_free(void* ptr)
{
	--mem_malloc_count;
	free(ptr);
}

int custom_random(int n) 
{
	int limit;
	int r;
	limit = RAND_MAX - (RAND_MAX % n);

	while ((r = rand()) >= limit);

	return r % n;
}