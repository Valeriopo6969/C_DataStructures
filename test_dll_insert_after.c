#define CLOVE_SUITE_NAME dll_InsertAfter
#include "clove.h"
#include "doubly_linked_lists.h"

dll_string_item* my_dlinked_list;

CLOVE_SUITE_SETUP() {
	my_dlinked_list = NULL;
}

CLOVE_SUITE_TEARDOWN() {
	free(my_dlinked_list);
}