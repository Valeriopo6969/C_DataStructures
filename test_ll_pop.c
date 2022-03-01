#define CLOVE_SUITE_NAME LL_POP
#include "clove.h"

#include "linked_lists.h"

ll_string_item* my_list;



CLOVE_SUITE_SETUP() {

	my_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	ll_string_item_list_free(&my_list);
}

CLOVE_TEST(NullItemFromEmptyList)
{
	ll_node* expected = ll_pop(&my_list);

	CLOVE_NULL(expected);
}

CLOVE_TEST(From1ItemList)
{
	ll_list_append_string(&my_list, "000");

	ll_string_item* result = ll_pop(&my_list);

	CLOVE_NOT_NULL(result);
	CLOVE_NULL(result->node.next);
	CLOVE_STRING_EQ("000", result->string);

	ll_string_item_list_free(&result);
}

CLOVE_TEST(From2ItemList)
{
	ll_list_append_string(&my_list, "000");
	ll_list_append_string(&my_list, "001");

	ll_string_item* result = ll_pop(&my_list);

	CLOVE_STRING_EQ("001", my_list->string);

	ll_string_item_list_free(&result);
}



