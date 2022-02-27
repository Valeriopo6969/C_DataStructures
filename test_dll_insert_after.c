#define CLOVE_SUITE_NAME dll_InsertAfter
#include "clove.h"
#include "doubly_linked_lists.h"

dll_string_item* my_dlinked_list;

CLOVE_SUITE_SETUP() {
	my_dlinked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_dlinked_list);
}

CLOVE_TEST(LastItemOfList)
{
	dll_string_item* item0 = dll_append_string(&my_dlinked_list, "000");
	dll_string_item* item1 = dll_insert_string_after(item0, "001");

	CLOVE_PTR_EQ(item0, item1->node.prev);
	CLOVE_PTR_EQ(item1, item0->node.next);
	CLOVE_NULL(item1->node.next);
}

CLOVE_TEST(FirstItemOf2ItemList)
{
	dll_string_item* item_first = dll_append_string(&my_dlinked_list, "first");
	dll_string_item* item_second = dll_append_string(&my_dlinked_list, "second");
	dll_string_item* item_middle = dll_insert_string_after(item_first, "middle");

	CLOVE_PTR_EQ(item_first->node.next, item_second->node.prev);
	
	CLOVE_PTR_EQ(item_middle->node.prev, item_first);
	CLOVE_PTR_EQ(item_middle->node.next, item_second);

}

CLOVE_TEST(NullNode)
{
	CLOVE_NULL(dll_insert_string_after(my_dlinked_list, "U will not insert me!"));
}
	

	
