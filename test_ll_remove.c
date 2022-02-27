#define CLOVE_SUITE_NAME ll_Remove
#include "clove.h"
#include "linked_lists.h"

string_item_t* my_linked_list;

CLOVE_SUITE_SETUP() {
	my_linked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_linked_list);
}

CLOVE_TEST(NullItemFromEmptyList)
{
	list_node_t* result = ll_list_remove(&my_linked_list, NULL);

	CLOVE_NULL(result);
}

CLOVE_TEST(ItemFromEmptyList)
{
	list_node_t* result = ll_list_remove(&my_linked_list, "Ciao");

	CLOVE_NULL(result);
}

CLOVE_TEST(ItemFrom1ItemList)
{
	string_item_t* test000 = ll_list_append_string(&my_linked_list, "test000");
	string_item_t* result = ll_list_remove(&my_linked_list, test000);

	CLOVE_NOT_NULL(result);
	CLOVE_STRING_EQ("test000", result->string);
}

CLOVE_TEST(FirstItemFrom2ItemList)
{
	string_item_t* test000 = ll_list_append_string(&my_linked_list, "test000");
	string_item_t* test001 = ll_list_append_string(&my_linked_list, "test001");
	string_item_t* result = ll_list_remove(&my_linked_list, test000);

	CLOVE_NULL(result->next);
	CLOVE_STRING_EQ("test001", my_linked_list->string);
}
	
CLOVE_TEST(MiddleItemFrom3ItemList)
{
	string_item_t* test000 = ll_list_append_string(&my_linked_list, "test000");
	string_item_t* test001 = ll_list_append_string(&my_linked_list, "test001");
	string_item_t* test002 = ll_list_append_string(&my_linked_list, "test002");

	ll_list_remove(&my_linked_list, test001);

	string_item_t* result = ll_list_get_tail(&my_linked_list);

	CLOVE_STRING_EQ("test000", my_linked_list->string);
	CLOVE_STRING_EQ("test002", result->string);
}
	





