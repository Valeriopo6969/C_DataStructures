#define CLOVE_SUITE_NAME LL_APPEND
#include "clove.h"


#include "linked_lists.h"

ll_string_item* my_list;



CLOVE_SUITE_SETUP() {

	my_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	ll_string_item_list_free(&my_list);
}

CLOVE_TEST(NullItemToEmptyList)
{
	ll_string_item* result = ll_append(&my_list, NULL);

	CLOVE_NULL(result);
}

CLOVE_TEST(1Item)
{
	ll_string_item* result = ll_list_append_string(&my_list, "000");
	
	
	CLOVE_PTR_EQ(result, my_list);
	CLOVE_NOT_NULL(result);

}

CLOVE_TEST(3Item)
{
	ll_string_item* result0 = ll_list_append_string(&my_list, "000");
	ll_string_item* result1 = ll_list_append_string(&my_list, "001");
	ll_string_item* result2 = ll_list_append_string(&my_list, "002");

	CLOVE_PTR_EQ(result0, my_list);
	CLOVE_PTR_EQ(result1, result0->node.next);
	CLOVE_PTR_EQ(result2, result1->node.next);
	CLOVE_NULL(result2->node.next);
}





	

