#define CLOVE_SUITE_NAME LL_REVERSE
#include "clove.h"


#include "linked_lists.h"

ll_string_item_t* my_list;



CLOVE_SUITE_SETUP() {

	my_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	ll_string_item_list_free(&my_list);
}

CLOVE_TEST(EmptyList)
{
	int result = ll_list_reverse(&my_list);

	CLOVE_IS_FALSE(result);
}

CLOVE_TEST(1ItemList)
{
	ll_list_append_string(&my_list, "000");

	int result = ll_list_reverse(&my_list);

	CLOVE_IS_TRUE(result);
	CLOVE_STRING_EQ("000", my_list->string);
}

CLOVE_TEST(2ItemList)
{
	ll_string_item_t* result0 = ll_list_append_string(&my_list, "000");
	ll_string_item_t* result1 = ll_list_append_string(&my_list, "001");

	ll_list_reverse(&my_list);

	CLOVE_STRING_EQ(result1->string, my_list->string);
	CLOVE_PTR_EQ(result0, my_list->node.next);
}

CLOVE_TEST(5ItemList)
{
	ll_string_item_t* result0 = ll_list_append_string(&my_list, "000");
	ll_string_item_t* result1 = ll_list_append_string(&my_list, "001");
	ll_string_item_t* result2 = ll_list_append_string(&my_list, "002");
	ll_string_item_t* result3 = ll_list_append_string(&my_list, "003");
	ll_string_item_t* result4 = ll_list_append_string(&my_list, "004");

	ll_list_reverse(&my_list);

	CLOVE_PTR_EQ(result4, my_list);
	CLOVE_PTR_EQ(result3, result4->node.next);
	CLOVE_PTR_EQ(result2, result3->node.next);
	CLOVE_PTR_EQ(result1, result2->node.next);
	CLOVE_PTR_EQ(result0, result1->node.next);
	CLOVE_NULL(result0->node.next);
}


	



	
	

