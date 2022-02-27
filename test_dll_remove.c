#define CLOVE_SUITE_NAME dll_Remove
#include "clove.h"
#include "doubly_linked_lists.h"

dll_string_item* my_dlinked_list;

CLOVE_SUITE_SETUP() {
	my_dlinked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_dlinked_list);
}

CLOVE_TEST(NullItemFromNullList)
{
	dll_node* result = dll_list_remove(&my_dlinked_list, NULL);
	CLOVE_NULL(result);
}
	


CLOVE_TEST(NullItem)
{
	dll_append_string(&my_dlinked_list, "Ciao");
	
	dll_node* result = dll_list_remove(&my_dlinked_list, NULL);

	CLOVE_NULL(result);
	CLOVE_STRING_EQ("Ciao", my_dlinked_list->string);
}

CLOVE_TEST(ItemFromNullList)
{
	dll_string_item* item_to_remove = dll_append_string(&my_dlinked_list, "Ciao");

	dll_list_remove(NULL, item_to_remove);


	CLOVE_NOT_NULL(item_to_remove);
}


CLOVE_TEST(FirstItemFrom1ItemList)
{
	dll_string_item* item_to_remove = dll_append_string(&my_dlinked_list, "Ciao");

	dll_list_remove(&my_dlinked_list, item_to_remove);

	CLOVE_NULL(my_dlinked_list);
}
	


CLOVE_TEST(FirstItemFrom2ItemList)
{
	dll_string_item* item0 = dll_append_string(&my_dlinked_list, "000");
	dll_string_item* item1 = dll_append_string(&my_dlinked_list, "001");

	dll_list_remove(&my_dlinked_list, item0);

	CLOVE_NOT_NULL(my_dlinked_list);
	CLOVE_NULL(my_dlinked_list->node.prev);
	CLOVE_NULL(my_dlinked_list->node.next);

	CLOVE_PTR_EQ(my_dlinked_list, item1);
	CLOVE_STRING_EQ("001", my_dlinked_list->string);
}
	
CLOVE_TEST(SecondItemFrom2ItemList)
{
	dll_string_item* item0 = dll_append_string(&my_dlinked_list, "000");
	dll_string_item* item1 = dll_append_string(&my_dlinked_list, "001");

	dll_list_remove(&my_dlinked_list, item1);

	CLOVE_NOT_NULL(my_dlinked_list);
	CLOVE_NULL(my_dlinked_list->node.prev);
	CLOVE_NULL(my_dlinked_list->node.next);

	CLOVE_PTR_EQ(my_dlinked_list, item0);
	CLOVE_STRING_EQ("000", my_dlinked_list->string);
}
	
CLOVE_TEST(SecondItemFrom3ItemList)
{
	dll_string_item* item0 = dll_append_string(&my_dlinked_list, "000");
	dll_string_item* item1 = dll_append_string(&my_dlinked_list, "001");
	dll_string_item* item2 = dll_append_string(&my_dlinked_list, "002");

	dll_list_remove(&my_dlinked_list, item1);

	CLOVE_PTR_EQ(item0->node.next, item2);
	CLOVE_PTR_EQ(item2->node.prev, item0);
}
	
CLOVE_TEST(2ItemFrom5ItemList)
{
	dll_string_item* item0 = dll_append_string(&my_dlinked_list, "000");
	dll_string_item* item1 = dll_append_string(&my_dlinked_list, "001");
	dll_string_item* item2 = dll_append_string(&my_dlinked_list, "002");
	dll_string_item* item3 = dll_append_string(&my_dlinked_list, "003");
	dll_string_item* item4 = dll_append_string(&my_dlinked_list, "004");

	dll_list_remove(&my_dlinked_list, item1);
	dll_list_remove(&my_dlinked_list, item3);
	
	CLOVE_PTR_EQ(item0->node.next, item2);
	CLOVE_PTR_EQ(item2->node.prev, item0);
	CLOVE_PTR_EQ(item2->node.next, item4);
	CLOVE_PTR_EQ(item4->node.prev, item2);
}
	
CLOVE_TEST(AlreadyRemovedItem)
{
	dll_string_item* item0 = dll_append_string(&my_dlinked_list, "000");
	dll_string_item* item1 = dll_append_string(&my_dlinked_list, "001");

	dll_node* first_removed = dll_list_remove(&my_dlinked_list, item1);
	dll_node* second_removed = dll_list_remove(&my_dlinked_list, item1);

	CLOVE_PTR_EQ(first_removed, second_removed);

	free(item1);
}


	
	



	

	
	
	


	
	


	

	
	



	


