#define CLOVE_SUITE_NAME DLL_APPEND
#include "clove.h"
#include "doubly_linked_lists.h"

#include "test_utils.h"

dll_string_item_t* my_list;

CLOVE_SUITE_SETUP() {
	my_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {

	dll_string_item_list_free(&my_list);
}

CLOVE_TEST(NullNode)
{
	dll_string_item_t* result = dll_append(&my_list, NULL);

	CLOVE_NULL(result);
}

CLOVE_TEST(1Item)
{
	dll_string_item_t* result = dll_append_string(&my_list, "000");

	CLOVE_STRING_EQ("000", my_list->string);
	CLOVE_NOT_NULL(my_list);
	CLOVE_PTR_EQ(result, my_list);
}

CLOVE_TEST(3Item)
{
	dll_string_item_t* result0 = dll_append_string(&my_list, "000");
	dll_string_item_t* result1 = dll_append_string(&my_list, "001");
	dll_string_item_t* result2 = dll_append_string(&my_list, "002");

	CLOVE_PTR_EQ(result0, result1->node.prev);
	CLOVE_PTR_EQ(result1, result0->node.next);
	CLOVE_PTR_EQ(result1, result2->node.prev);
	CLOVE_PTR_EQ(result2, result1->node.next);

	CLOVE_NULL(result0->node.prev);
	CLOVE_NULL(result2->node.next);
}






	

	



	

	




	





	

