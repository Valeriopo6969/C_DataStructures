#define CLOVE_SUITE_NAME ll_Reverse
#include "clove.h"
#include "linked_lists.h"

string_item_t* my_linked_list;

CLOVE_SUITE_SETUP() {
	my_linked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_linked_list);
}

CLOVE_TEST(EmptyList)
{
	int result = ll_list_reverse(&my_linked_list);

	CLOVE_IS_FALSE(result);
}

CLOVE_TEST(1ItemList)
{
	ll_list_append_string(&my_linked_list, "Ciao");

	int result = ll_list_reverse(&my_linked_list);

	CLOVE_IS_TRUE(result);
	CLOVE_STRING_EQ("Ciao", my_linked_list->string);
}

CLOVE_TEST(2ItemList)
{
	ll_list_append_string(&my_linked_list, "Ciao, ");
	ll_list_append_string(&my_linked_list, "Come va?");

	ll_list_reverse(&my_linked_list);
	
	string_item_t* result = ll_list_get_tail(&my_linked_list);
	
	CLOVE_STRING_EQ("Come va?", my_linked_list->string);
	CLOVE_STRING_EQ("Ciao, ", result->string);
}

CLOVE_TEST(5ItemList)
{
	ll_list_append_string(&my_linked_list, "000");
	ll_list_append_string(&my_linked_list, "001");
	ll_list_append_string(&my_linked_list, "002");
	ll_list_append_string(&my_linked_list, "003");
	ll_list_append_string(&my_linked_list, "004");

	ll_list_reverse(&my_linked_list);

	string_item_t* result0 = ll_list_pop(&my_linked_list);
	string_item_t* result1 = ll_list_pop(&my_linked_list);
	string_item_t* result2 = ll_list_pop(&my_linked_list);
	string_item_t* result3 = ll_list_pop(&my_linked_list);
	string_item_t* result4 = ll_list_pop(&my_linked_list);

	CLOVE_STRING_EQ("004", result0->string);
	CLOVE_STRING_EQ("003", result1->string);
	CLOVE_STRING_EQ("002", result2->string);
	CLOVE_STRING_EQ("001", result3->string);
	CLOVE_STRING_EQ("000", result4->string);
	
}