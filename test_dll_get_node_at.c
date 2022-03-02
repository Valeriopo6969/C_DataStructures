#define CLOVE_SUITE_NAME DLL_GET_NODE_AT
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

CLOVE_TEST(InvalidIndex)
{
	dll_append_string(&my_list, "000");
	dll_append_string(&my_list, "001");
	dll_append_string(&my_list, "002");

	dll_string_item_t* result = dll_get_node_at(my_list, 3); // 3 > than list length (node at is 0 inclusive)

	CLOVE_NULL(result);
}

CLOVE_TEST(ValidIndex)
{
	dll_string_item_t* item0 = dll_append_string(&my_list, "000");
	dll_string_item_t* item1 = dll_append_string(&my_list, "001");
	dll_string_item_t* item2 = dll_append_string(&my_list, "002");

	dll_string_item_t* result = dll_get_node_at(my_list, 2); 

	CLOVE_PTR_EQ(item2, result);
}