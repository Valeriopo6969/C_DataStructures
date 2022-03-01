#pragma once

#ifdef TEST_DEBUG

#include "test_utils.h"

#endif 

typedef struct list_node
{
	struct list_node* next;
}ll_node;

typedef struct string_item
{
	const ll_node node;
	const char* string;
}ll_string_item;

/// <summary>
/// Returns the last node of list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns>last node of the list</returns>
ll_node* ll_get_tail(ll_node** head);
/// <summary>
/// Removes the first node of list and sets, if it isn't NULL, the next node as the new head
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns><para>The first node of the list;</para>NULL if u are asking for an empty list;</returns>
ll_node* ll_pop(ll_node** head);
/// <summary>
/// Appends node to the last node of the list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="node">: the node u want to append</param>
/// <returns><para>The node u appended to list;</para>NULL if u were trying to append a NULL node;</returns>
ll_node* ll_append( ll_node** head,  ll_node* node);
/// <summary>
/// Removes the requested node from the list by settings his .next node to NULL
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="node">: the node u want to remove</param>
/// <returns><para>The node u removed;</para>NULL if u are asking for an empty list or trying to remove a NULL node;</returns>
ll_node* ll_remove(ll_node** head, ll_node* node);
/// <summary>
/// Revert the list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns>
/// <para>TRUE (1) if the list isn't empty;</para>
/// FALSE (0) if u are asking to revert an empty list;
/// </returns>
int ll_list_reverse(ll_node** head);
/// <summary>
/// Allocates memory to instantiate a new ll_string_item* and assign to his .string field the string u passed in
/// </summary>
/// <param name="string">content of the .string field</param>
/// <returns>The instantiated ll_string_item;</returns>
ll_string_item* ll_string_item_new(const char* string);
/// <summary>
/// Manages to correctly free previously memory allocated
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
void ll_list_free(ll_node** head);

#define ll_list_append_string(head, item) ll_append((ll_node**)head,(ll_node *)ll_string_item_new(item));
#define ll_string_item_list_free(head) ll_list_free((ll_node**)head)









