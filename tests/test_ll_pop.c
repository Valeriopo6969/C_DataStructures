#define CLOVE_SUITE_NAME ll_Pop
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
	list_node_t* expected = ll_list_pop(&my_linked_list);

	CLOVE_NULL(expected);
}

CLOVE_TEST(ItemFrom1ItemList)
{
	ll_list_append_string(&my_linked_list, "Ciao");

	string_item_t* result = ll_list_pop(&my_linked_list);

	CLOVE_NOT_NULL(result);
	CLOVE_STRING_EQ("Ciao", result->string);
}

