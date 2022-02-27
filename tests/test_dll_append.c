#define CLOVE_SUITE_NAME dll_Append
#include "clove.h"
#include "doubly_linked_lists.h"

dll_string_item* my_dlinked_list;

CLOVE_SUITE_SETUP() {
	my_dlinked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_dlinked_list);
}

CLOVE_TEST(NullItem)
{
	dll_node* result = dll_append(&my_dlinked_list, NULL);

	CLOVE_NULL(result);
}

CLOVE_TEST(1Item)
{

	dll_append_string(&my_dlinked_list, "1");
	
	CLOVE_STRING_EQ("1", my_dlinked_list->string);
	CLOVE_NOT_NULL(my_dlinked_list);
}

CLOVE_TEST(3Item)
{
	dll_append_string(&my_dlinked_list, "000");
	dll_append_string(&my_dlinked_list, "001");
	dll_append_string(&my_dlinked_list, "002");

	int length = dll_list_get_length(&my_dlinked_list);
	CLOVE_INT_EQ(3, length);

	dll_string_item* result0 = dll_list_pop(&my_dlinked_list);
	dll_string_item* result1 = dll_list_pop(&my_dlinked_list);
	dll_string_item* result2 = dll_list_pop(&my_dlinked_list);

	CLOVE_STRING_EQ("000", result0->string);
	CLOVE_STRING_EQ("001", result1->string);
	CLOVE_STRING_EQ("002", result2->string);

	free(result0);
	free(result1);
	free(result2);
}

CLOVE_TEST(shuffle)
{
	dll_append_string(&my_dlinked_list, "000");
	dll_append_string(&my_dlinked_list, "001");
	dll_append_string(&my_dlinked_list, "002");
	dll_append_string(&my_dlinked_list, "003");
	

	dll_list_shuffle(&my_dlinked_list);

	dll_string_item* result0 = dll_get_node_at(&my_dlinked_list,0);
	dll_string_item* result1 = dll_get_node_at(&my_dlinked_list,1);
	dll_string_item* result2 = dll_get_node_at(&my_dlinked_list,2);
	dll_string_item* result3 = dll_get_node_at(&my_dlinked_list,3);

	CLOVE_STRING_EQ("001", result0->string);
	CLOVE_STRING_EQ("003", result1->string);
	CLOVE_STRING_EQ("000", result2->string);
	CLOVE_STRING_EQ("002", result3->string);

}
	





	

