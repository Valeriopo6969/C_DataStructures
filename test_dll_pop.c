#define CLOVE_SUITE_NAME DLL_POP
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

CLOVE_TEST(EmptyList)
{
	dll_node_t* result = dll_pop(&my_list);

	CLOVE_NULL(result);
}

CLOVE_TEST(From1ItemList)
{
	dll_string_item_t* item0 = dll_append_string(&my_list, "000");
	dll_string_item_t* result = dll_pop(&my_list);

	CLOVE_NOT_NULL(result);
	CLOVE_NULL(my_list);
	dll_string_item_list_free(&result);
}

CLOVE_TEST(From2ItemList)
{
	dll_string_item_t* item0 = dll_append_string(&my_list, "000");
	dll_string_item_t* item1 = dll_append_string(&my_list, "001");
	dll_string_item_t* result = dll_pop(&my_list);

	CLOVE_NOT_NULL(my_list);
	CLOVE_NULL(item0->node.next);
	CLOVE_NULL(item1->node.prev);
	CLOVE_PTR_EQ(my_list, item1);
	dll_string_item_list_free(&result);
}
