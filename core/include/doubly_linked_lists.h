#pragma once

#ifdef TEST_DEBUG

#include "test_utils.h"

#endif 

typedef struct dlist_node
{
	struct dlist_node* prev;
	struct dlist_node* next;
}dll_node_t;

typedef struct dstring_item
{
	dll_node_t node;
	const char* string;
}dll_string_item_t;

/// <summary>
/// Returns the last node of list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns>last node of the list</returns>
dll_node_t* dll_get_tail(dll_node_t** head);

/// <summary>
/// Removes the first node of list and sets, if it isn't NULL, the next node as the new head
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns><para>The first node of the list;</para>NULL if u are asking for an empty list;</returns>
dll_node_t* dll_pop(dll_node_t** head);

/// <summary>
/// Appends node to the last node of the list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="node">: the node u want to append</param>
/// <returns><para>The node u appended to list;</para>NULL if u were trying to append a NULL node;</returns>
dll_node_t* dll_append(dll_node_t** head, dll_node_t* node);

/// <summary>
/// Removes the requested node from the list by settings his .prev and .next node to NULL
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="node">: the node u want to remove</param>
/// <returns><para>The node u removed;</para>NULL if u are asking for an empty list or trying to remove a NULL node;</returns>
dll_node_t* dll_remove(dll_node_t** head, dll_node_t* node);

/// <summary>
/// Insert a node after a requested valid node (not NULL)
/// </summary>
/// <param name="node">: the node from which the "node_to_insert" node will be inserted </param>
/// <param name="node_to_insert">: the node node u want to insert after the requested node</param>
/// <returns><para>The node u inserted;</para>NULL if u requested a NULL node;</returns>
dll_node_t* dll_insert_after(dll_node_t* node, dll_node_t* node_to_insert);

/// <summary>
/// Insert a node before a requested valid node (not NULL)
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="node">: the node from which the "node_to_insert" node will be inserted </param>
/// <param name="node_to_insert">: the node node u want to insert before the requested node</param>
/// <returns><para>The node u inserted;</para>NULL if u requested a NULL node;</returns>
dll_node_t* dll_insert_before(dll_node_t** head, dll_node_t* node, dll_node_t* node_to_insert);

/// <summary>
///  Returns the node that is at the requested index value of a list, range from 0-n
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="index">: the point were the node u are asking should be</param>
/// <returns>
/// The node u are asking for;
/// <para>NULL if the index value is longer than the actual length of the list;</para>
/// </returns>
dll_node_t* dll_get_node_at(dll_node_t** head, int index);

/// <summary>
/// Shuffles, randomically, the order in which the list's nodes were previously appendend
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns>
/// <para>TRUE (1) if the list isn't empty;</para>
/// FALSE (0) if u are asking to shuffle an empty list;
/// </returns>
int dll_shuffle(dll_node_t** head);

/// <summary>
/// Returns the current number of elements in the list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns>The number of elements that are on the requested list;</returns>
int dll_get_length(dll_node_t** head);

/// <summary>
/// Allocates memory to instantiate a new dll_string_item* and assign to his .string field the string u passed in
/// </summary>
/// <param name="string">content of the .string field</param>
/// <returns>The instantiated dll_string_item;</returns>
dll_string_item_t* dll_string_item_new(const char* string);

/// <summary>
/// Manages to correctly free previously memory allocated
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
void dll_list_free(dll_node_t** head);


#define dll_append_string(head, string) dll_append((dll_node_t**)head,(dll_node_t*)dll_string_item_new(string))
#define dll_insert_string_after(node, string) dll_insert_after((dll_node_t*)node,(dll_node_t*)dll_string_item_new(string))
#define dll_insert_string_before(head, node, string) dll_insert_before((dll_node_t**)head, (dll_node_t*)node,(dll_node_t*)dll_string_item_new(string))
#define dll_string_item_list_free(head) dll_list_free((dll_node_t**)head)






























