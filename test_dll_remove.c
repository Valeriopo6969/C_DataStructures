#define CLOVE_SUITE_NAME DLL_REMOVE
#include "clove.h"
#include "doubly_linked_lists.h"


#include "test_utils.h"

dll_string_item* my_list;

CLOVE_SUITE_SETUP() {

	my_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {

	dll_string_item_list_free(&my_list);
}

CLOVE_TEST(NullNodeFromNullList)
{
	dll_node* result = dll_remove(&my_list, NULL);
	CLOVE_NULL(result);
}

CLOVE_TEST(NullNodeFrom1ItemList)
{
	dll_append_string(&my_list, "000");

	dll_node* result = dll_remove(&my_list, NULL);

	CLOVE_NULL(result);
	CLOVE_STRING_EQ("000", my_list->string);
}

CLOVE_TEST(1ItemFromNullList)
{
	dll_string_item* item_to_remove = dll_append_string(&my_list, "000");

	dll_remove(NULL, item_to_remove);

	CLOVE_NOT_NULL(item_to_remove);
	CLOVE_STRING_EQ("000", item_to_remove->string);
}

CLOVE_TEST(FirstItemFrom1ItemList)
{
	dll_string_item* item_to_remove = dll_append_string(&my_list, "000");

	dll_remove(&my_list, item_to_remove);

	CLOVE_NULL(my_list);
	CLOVE_PTR_NE(item_to_remove, my_list);
	dll_string_item_list_free(item_to_remove);
}

CLOVE_TEST(FirstItemFrom2ItemList)
{
	dll_string_item* item0 = dll_append_string(&my_list, "000");
	dll_string_item* item1 = dll_append_string(&my_list, "001");

	dll_remove(&my_list, item0);

	CLOVE_NOT_NULL(my_list);
	CLOVE_NULL(my_list->node.prev);
	CLOVE_NULL(my_list->node.next);

	CLOVE_PTR_EQ(my_list, item1);
	CLOVE_STRING_EQ("001", my_list->string);
	dll_string_item_list_free(item0);
}

CLOVE_TEST(SecondItemFrom2ItemList)
{
	dll_string_item* item0 = dll_append_string(&my_list, "000");
	dll_string_item* item1 = dll_append_string(&my_list, "001");

	dll_remove(&my_list, item1);

	CLOVE_NOT_NULL(my_list);
	CLOVE_NULL(my_list->node.prev);
	CLOVE_NULL(my_list->node.next);

	CLOVE_PTR_EQ(my_list, item0);
	CLOVE_STRING_EQ("000", my_list->string);
	dll_string_item_list_free(item1);
}

CLOVE_TEST(SecondItemFrom3ItemList)
{
	dll_string_item* item0 = dll_append_string(&my_list, "000");
	dll_string_item* item1 = dll_append_string(&my_list, "001");
	dll_string_item* item2 = dll_append_string(&my_list, "002");

	dll_remove(&my_list, item1);

	CLOVE_PTR_EQ(item0->node.next, item2);
	CLOVE_PTR_EQ(item2->node.prev, item0);
	dll_string_item_list_free(item1);
}

CLOVE_TEST(2ItemFrom5ItemList)
{
	dll_string_item* item0 = dll_append_string(&my_list, "000");
	dll_string_item* item1 = dll_append_string(&my_list, "001");
	dll_string_item* item2 = dll_append_string(&my_list, "002");
	dll_string_item* item3 = dll_append_string(&my_list, "003");
	dll_string_item* item4 = dll_append_string(&my_list, "004");

	dll_remove(&my_list, item1);
	dll_remove(&my_list, item3);

	CLOVE_PTR_EQ(item0->node.next, item2);
	CLOVE_PTR_EQ(item2->node.prev, item0);
	CLOVE_PTR_EQ(item2->node.next, item4);
	CLOVE_PTR_EQ(item4->node.prev, item2);

	dll_string_item_list_free(item1);
	dll_string_item_list_free(item3);
}

CLOVE_TEST(AlreadyRemovedItem)
{
	dll_string_item* item0 = dll_append_string(&my_list, "000");
	dll_string_item* item1 = dll_append_string(&my_list, "001");

	dll_node* first_removed = dll_remove(&my_list, item1);
	dll_node* second_removed = dll_remove(&my_list, item1);

	CLOVE_PTR_EQ(first_removed, second_removed);

	dll_string_item_list_free(item1);
}





	



	

	



	
	



	

	
	
	


	
	


	

	
	



	


