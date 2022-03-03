#pragma once

extern int mem_malloc_count;

#ifdef TEST_DEBUG 
	#define malloc mem_malloc
	#define free mem_free
#endif

/// <summary>
/// Mocked malloc function for testing
/// </summary>
void* mem_malloc(size_t size);

/// <summary>
/// Mocked free function for testing
/// </summary>
void mem_free(void* ptr);

/// <summary>
/// <para>Return a uniform random value in the range 0..n-1 inclusive;</para>
/// More detailed info at randRange() algorithm: 
/// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html
/// </summary>
int custom_random(int n);

