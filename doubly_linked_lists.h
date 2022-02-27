#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct dlist_node
{
	struct dlist_node* prev;
	struct dlist_node* next;
}dll_node;

typedef struct dstring_item
{
	const struct dlist_node node;
	const char* string;
}dll_string_item;

dll_string_item* dll_string_item_new(const char* string);

dll_node* dll_get_tail(dll_node** head);
dll_node* dll_list_pop(dll_node** head);
int dll_list_shuffle(dll_node** head);

int dll_list_get_length(dll_node** head);

dll_node* dll_get_node_at(dll_node** head, int index);
dll_node* dll_append(dll_node** head, dll_node* item);
dll_node* dll_list_remove(dll_node** head, dll_node* item);
dll_node* dll_insert_after(dll_node* node, dll_node* item_to_insert);
dll_node* dll_insert_before(dll_node* node, dll_node* item_to_insert);

#define dll_append_string(head, item) dll_append((dll_node**)head,(dll_node*)dll_string_item_new(item))
#define dll_insert_string_after(node, item_to_insert) dll_insert_after((dll_node*)node,(dll_node*)dll_string_item_new(item_to_insert))
#define dll_insert_string_before(node, item_to_insert) dll_insert_before((dll_node*)node,(dll_node*)dll_string_item_new(item_to_insert))



















