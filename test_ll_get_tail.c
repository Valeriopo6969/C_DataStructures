#define CLOVE_SUITE_NAME ll_GetTail
#include "clove.h"
#include "linked_lists.h"

string_item_t* my_linked_list;

CLOVE_SUITE_SETUP() {
	my_linked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_linked_list);
}

CLOVE_TEST(FromEmptyList)
{
	list_node_t* expected = ll_list_get_tail(&my_linked_list);

	CLOVE_NULL(expected);
}
	
CLOVE_TEST(From1ItemList)
{
	ll_list_append_string(&my_linked_list, "Ciao");

	string_item_t* result = ll_list_get_tail(&my_linked_list);

	CLOVE_STRING_EQ("Ciao", result->string);
	CLOVE_NOT_NULL(result);
}


	


	







