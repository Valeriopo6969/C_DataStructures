#pragma once

#ifdef TEST_DEBUG

#include "test_utils.h"

#endif 

typedef struct dlist_node
{
	struct dlist_node* prev;
	struct dlist_node* next;
}dll_node;

typedef struct dstring_item
{
	const dll_node node;
	const char* string;
}dll_string_item;

/// <summary>
/// Returns the last node of list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns>last node of the list</returns>
dll_node* dll_get_tail(dll_node** head);

/// <summary>
/// Removes the first node of list and sets, if it isn't NULL, the next node as the new head
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns><para>The first node of the list;</para>NULL if u are asking for an empty list;</returns>
dll_node* dll_pop(dll_node** head);

/// <summary>
/// Appends node to the last node of the list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="node">: the node u want to append</param>
/// <returns><para>The node u appended to list;</para>NULL if u were trying to append a NULL node;</returns>
dll_node* dll_append(dll_node** head, dll_node* node);

/// <summary>
/// Removes the requested node from the list by settings his .prev and .next node to NULL
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="node">: the node u want to remove</param>
/// <returns><para>The node u removed;</para>NULL if u are asking for an empty list or trying to remove a NULL node;</returns>
dll_node* dll_remove(dll_node** head, dll_node* node);

/// <summary>
/// Insert a node after a requested valid node (not NULL)
/// </summary>
/// <param name="node">: the node from which the "node_to_insert" node will be inserted </param>
/// <param name="node_to_insert">: the node node u want to insert after the requested node</param>
/// <returns><para>The node u inserted;</para>NULL if u requested a NULL node;</returns>
dll_node* dll_insert_after(dll_node* node, dll_node* node_to_insert);

/// <summary>
/// Insert a node before a requested valid node (not NULL)
/// </summary>
/// <param name="node">: the node from which the "node_to_insert" node will be inserted </param>
/// <param name="node_to_insert">: the node node u want to insert before the requested node</param>
/// <returns><para>The node u inserted;</para>NULL if u requested a NULL node;</returns>
dll_node* dll_insert_before(dll_node* node, dll_node* node_to_insert);

/// <summary>
///  Returns the node that is at the requested index value of a list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <param name="index">: the point were the node u are asking should be</param>
/// <returns>
/// The node u are asking for;
/// <para>NULL if the index value is longer than the actual </para>
/// length of the list or if u asked for a node that isn't part of it;
/// </returns>
dll_node* dll_get_node_at(dll_node** head, int index);

/// <summary>
/// Shuffles, randomically, the order in which the list's nodes were previously appendend
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns>
/// <para>TRUE (1) if the list isn't empty;</para>
/// FALSE (0) if u are asking to shuffle an empty list;
/// </returns>
int dll_shuffle(dll_node** head);

/// <summary>
/// Returns the current number of elements in the list
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
/// <returns>The number of elements that are on the requested list;</returns>
int dll_get_length(dll_node** head);
/// <summary>
/// Allocates memory to instantiate a new dll_string_item* and assign to his .string field the string u passed in
/// </summary>
/// <param name="string">content of the .string field</param>
/// <returns>The instantiated dll_string_item;</returns>
dll_string_item* dll_string_item_new(const char* string);

/// <summary>
/// Manages to correctly free previously memory allocated
/// </summary>
/// <param name="head">: reference to the "head" node of the list</param>
void dll_list_free(dll_node** head);


#define dll_append_string(head, item) dll_append((dll_node**)head,(dll_node*)dll_string_item_new(item))
#define dll_insert_string_after(node, item_to_insert) dll_insert_after((dll_node*)node,(dll_node*)dll_string_item_new(item_to_insert))
#define dll_insert_string_before(node, item_to_insert) dll_insert_before((dll_node*)node,(dll_node*)dll_string_item_new(item_to_insert))
#define dll_string_item_list_free(head) dll_list_free((dll_node**)head)





























