#define CLOVE_SUITE_NAME DLL_INSERT_BEFORE
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

CLOVE_TEST(EmptyNode)
{
	dll_string_item_t* result = dll_insert_string_after(my_list, "000");

	CLOVE_NULL(result);
	CLOVE_PTR_EQ(my_list, result);
}

CLOVE_TEST(FirstItemOf1ItemList)
{
	dll_string_item_t* item0 = dll_append_string(&my_list, "000");
	dll_string_item_t* item1 = dll_insert_string_before(&my_list, item0, "001");

	CLOVE_NULL(item0->node.next);
	CLOVE_NULL(item1->node.prev);
	CLOVE_PTR_EQ(item1, item0->node.prev);
	CLOVE_PTR_EQ(item0, item1->node.next);
}

CLOVE_TEST(SecondItemOf2ItemList)
{
	dll_string_item_t* item0 = dll_append_string(&my_list, "000");
	dll_string_item_t* item1 = dll_append_string(&my_list, "001");
	dll_string_item_t* item2 = dll_insert_string_before(&my_list, item1, "002");

	CLOVE_PTR_EQ(item2, item0->node.next);
	CLOVE_PTR_EQ(item2, item1->node.prev);
	CLOVE_PTR_EQ(item0, item2->node.prev);
	CLOVE_PTR_EQ(item1, item2->node.next);
}
