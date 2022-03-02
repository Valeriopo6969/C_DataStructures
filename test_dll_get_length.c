#define CLOVE_SUITE_NAME DLL_GET_LENGTH
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

CLOVE_TEST(2ItemList)
{
	dll_append_string(&my_list, "000");
	dll_append_string(&my_list, "001");

	int result = dll_get_length(my_list);

	CLOVE_INT_EQ(result, 2);
}

CLOVE_TEST(5ItemList)
{
	dll_append_string(&my_list, "000");
	dll_append_string(&my_list, "001");
	dll_append_string(&my_list, "002");
	dll_append_string(&my_list, "003");
	dll_append_string(&my_list, "004");

	int result = dll_get_length(my_list);

	CLOVE_INT_EQ(result, 5);
}