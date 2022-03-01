#define CLOVE_SUITE_NAME LL_GET_TAIL
#include "clove.h"


#include "linked_lists.h"

ll_string_item* my_list;

CLOVE_SUITE_SETUP() {
	my_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	ll_string_item_list_free(&my_list);
}

CLOVE_TEST(FromEmptyList)
{
	ll_node* expected = ll_get_tail(&my_list);

	CLOVE_NULL(expected);
}
	
CLOVE_TEST(From1ItemList)
{
	ll_list_append_string(&my_list, "000");

	ll_string_item* result = ll_get_tail(&my_list);

	CLOVE_STRING_EQ("000", result->string);
	CLOVE_NOT_NULL(result);
}


	


	







