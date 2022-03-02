#define CLOVE_SUITE_NAME LL_REMOVE
#include "clove.h"

#include "linked_lists.h"

ll_string_item_t* my_list;

CLOVE_SUITE_SETUP() {
	my_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	ll_string_item_list_free(&my_list);
}


CLOVE_TEST(NullItemFromEmptyList)
{
	ll_node_t* result = ll_remove(&my_list, NULL);

	CLOVE_NULL(result);
}

CLOVE_TEST(ItemFromEmptyList)
{
	ll_node_t* result = ll_remove(&my_list, "000");

	CLOVE_NULL(result);
}

CLOVE_TEST(ItemFrom1ItemList)
{
	ll_string_item_t* test000 = ll_list_append_string(&my_list, "000");
	ll_string_item_t* result = ll_remove(&my_list, test000);

	CLOVE_NOT_NULL(result);
	CLOVE_STRING_EQ("000", result->string);
	ll_string_item_list_free(&result);
}

CLOVE_TEST(FirstItemFrom2ItemList)
{
	ll_string_item_t* test000 = ll_list_append_string(&my_list, "000");
	ll_string_item_t* test001 = ll_list_append_string(&my_list, "001");
	ll_string_item_t* result = ll_remove(&my_list, test000);

	CLOVE_NULL(result->node.next);
	CLOVE_STRING_EQ("001", my_list->string);
	ll_string_item_list_free(&result);
}
	
CLOVE_TEST(MiddleItemFrom3ItemList)
{
	ll_string_item_t* test000 = ll_list_append_string(&my_list, "000");
	ll_string_item_t* test001 = ll_list_append_string(&my_list, "001");
	ll_string_item_t* test002 = ll_list_append_string(&my_list, "002");

	ll_string_item_t* result = ll_remove(&my_list, test001);

	CLOVE_PTR_EQ(test002, my_list->node.next);
	ll_string_item_list_free(&result);
}







