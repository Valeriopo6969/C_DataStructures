#pragma once

#include <stddef.h>
#include <stdlib.h>

typedef struct list_node
{
	struct list_node* next;
}list_node_t;

typedef struct string_item
{
	struct list_node* next;
	const char* string;
}string_item_t;

string_item_t* ll_string_item_new(const char* string);


 list_node_t* ll_list_get_tail( list_node_t** head);

 list_node_t* ll_list_pop( list_node_t** head);

 list_node_t* ll_list_append( list_node_t** head,  list_node_t* item);

 list_node_t* ll_list_remove(list_node_t** head, list_node_t* item);

 int ll_list_reverse(list_node_t** head);

#define ll_list_append_string(head, item) ll_list_append((list_node_t**)head,(list_node_t *)ll_string_item_new(item));








