#define CLOVE_SUITE_NAME MEMORYALLOCATION
#include "clove.h"
#include "test_utils.h"

CLOVE_TEST(Correct)
{
	CLOVE_INT_EQ(0, mem_malloc_count);
}




