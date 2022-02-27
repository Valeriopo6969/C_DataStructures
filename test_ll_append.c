#define CLOVE_SUITE_NAME ll_Append
#include "clove.h"
#include "linked_lists.h"

string_item_t* my_linked_list;

CLOVE_SUITE_SETUP() {
	my_linked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_linked_list);
}

CLOVE_TEST(NullItemToEmptyList)
{
	string_item_t* result = ll_list_append(&my_linked_list, NULL);

	CLOVE_NULL(result);
}

CLOVE_TEST(ItemTo1ItemList)
{
	ll_list_append_string(&my_linked_list, "Ciao");

	list_node_t* result = ll_list_get_tail(&my_linked_list);

	CLOVE_NOT_NULL(result);
	
}

CLOVE_TEST(ToEmptyList)
{
	string_item_t* result = ll_list_append_string(&my_linked_list, "Ciao");

	CLOVE_STRING_EQ("Ciao", result->string);
	CLOVE_PTR_EQ(result, my_linked_list);
}
	
	

	

