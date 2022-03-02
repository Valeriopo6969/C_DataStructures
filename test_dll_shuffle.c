#define CLOVE_SUITE_NAME DLL_SHUFFLE
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

CLOVE_TEST(Shuffle) 
{
	dll_append_string(&my_list, "000");
	dll_append_string(&my_list, "001");
	dll_append_string(&my_list, "002");
	dll_append_string(&my_list, "003");

	dll_shuffle(&my_list);

	dll_string_item_t* result0 = dll_get_node_at(&my_list, 0);
	dll_string_item_t* result1 = dll_get_node_at(&my_list, 1);
	dll_string_item_t* result2 = dll_get_node_at(&my_list, 2);
	dll_string_item_t* result3 = dll_get_node_at(&my_list, 3);

	CLOVE_STRING_EQ("001", result0->string);
	CLOVE_STRING_EQ("003", result1->string);
	CLOVE_STRING_EQ("000", result2->string);
	CLOVE_STRING_EQ("002", result3->string);
}