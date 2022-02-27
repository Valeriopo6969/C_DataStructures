#define CLOVE_SUITE_NAME dll_InsertBefore
#include "clove.h"
#include "doubly_linked_lists.h"

dll_string_item* my_dlinked_list;

CLOVE_SUITE_SETUP() {
	my_dlinked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_dlinked_list);
}

CLOVE_TEST(FirstItemOfList)
{
	dll_string_item* item0 = dll_append_string(&my_dlinked_list, "000");
	dll_string_item* item1 = dll_insert_string_before(item0, "001");

	CLOVE_NULL(item1->node.prev);
	CLOVE_NULL(item0->node.next);

	CLOVE_PTR_EQ(item1->node.next, item0);
	CLOVE_PTR_EQ(item0->node.prev, item1);
}



CLOVE_TEST(SecondItemOf2ItemList)
{
	dll_string_item* item_first = dll_append_string(&my_dlinked_list, "first");
	dll_string_item* item_second = dll_append_string(&my_dlinked_list, "second");
	dll_string_item* item_to_insert = dll_insert_string_before(item_second, "inserted_item");

	CLOVE_PTR_EQ(item_first->node.next, item_second->node.prev);

	CLOVE_PTR_EQ(item_to_insert->node.prev, item_first);
	CLOVE_PTR_EQ(item_to_insert->node.next, item_second);
}

CLOVE_TEST(NullNode)
{
	CLOVE_NULL(dll_insert_string_before(my_dlinked_list, "U will not insert me!"));
}


