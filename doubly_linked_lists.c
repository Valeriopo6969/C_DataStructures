#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define TEST_DEBUG
#include "doubly_linked_lists.h"

void dll_list_free(dll_node_t** head)
{
	dll_string_item_t* to_free;
	while ((to_free = dll_pop(head)))
	{
		free(to_free);
		to_free = NULL;
	}
}

dll_node_t* dll_append(dll_node_t** head, dll_node_t* node)
{
	if (!node) return NULL;

	dll_node_t* tail = dll_get_tail(head);

	if (!tail)
	{
		*head = node;
	}
	else
	{
		tail->next = node;
	}
	node->prev = tail;
	node->next = NULL;
	return node;
}

dll_node_t* dll_get_tail(dll_node_t** head) {

	dll_node_t* current_node = *head;
	if (!current_node)
	{
		return NULL;
	}

	while (current_node->next)
	{
		current_node = current_node->next;
	}
	return current_node;
}

dll_node_t* dll_pop(dll_node_t** head)
{
	dll_node_t* current_node = *head;
	
	if (!current_node)
	{
		return NULL;
	}

	*head = (*head)->next;
	if(*head)
		(*head)->prev = current_node->prev;
	current_node->next = NULL;

	return current_node;
}

dll_node_t* dll_remove(dll_node_t** head, dll_node_t* node)
{
	if (!head || !node) return NULL;

	//if first item
	if (*head == node)
		*head = node->next;

	if (node->next)
		node->next->prev = node->prev;

	if (node->prev)
		node->prev->next = node->next;

	node->next = NULL;
	node->prev = NULL;

	return node;
}

dll_node_t* dll_get_node_at(dll_node_t* head, int index)
{
	if (!head) return NULL; //u can't access a NULL pointer

	while (head && index > 0)
	{
		index--;
		head = head->next;
	}

	if (index > 0) return NULL; //exceeded list max length
	return head;
}

int dll_get_length(dll_node_t* head)
{
	
	int counter = 0;

	while (head)
	{
		counter++;

		head = head->next;
	}

	return counter;
}

int dll_shuffle(dll_node_t** head)
{
	if (!(*head)) return 0;

	int index = 0;
	index = dll_get_length((*head));

	while (index > 0)
	{
		int node_at = custom_random(index);						//using a 'fake' random method to generate testable result
		dll_node_t* item = dll_get_node_at((*head), node_at);	// taking a node at random valid index
		dll_node_t* item_removed = dll_remove(head, item);		// removing it from the list...
		dll_append(head, item_removed);							// ...then append it to the same list

		index--;												//decreasing the index value so next time won't shuffle an already shuffled node
	}

	return 1;
}

dll_node_t* dll_insert_after(dll_node_t* node, dll_node_t* node_to_insert)
{
	if (!node)
	{
		free((dll_string_item_t*)node_to_insert);
		node_to_insert = NULL;
		return NULL;
	}; //u can't access a NULL pointer

	node_to_insert->next = node->next;

	node->next = node_to_insert;

	node_to_insert->prev = node;

	if (node_to_insert->next)
		node_to_insert->next->prev = node_to_insert;

	return node_to_insert;
}

dll_node_t* dll_insert_before(dll_node_t** head, dll_node_t* node, dll_node_t* node_to_insert)
{
	if (!node)
	{
		free((dll_string_item_t*)node_to_insert);
		node_to_insert = NULL;
		return NULL;
	}; //u can't access a NULL pointer

	node_to_insert->prev = node->prev;

	node->prev = node_to_insert;

	node_to_insert->next = node;

	if (node_to_insert->prev)
		node_to_insert->prev->next = node_to_insert;
	else
		*head = node_to_insert;

	return node_to_insert;
}

dll_string_item_t* dll_string_item_new(const char* string)
{
	dll_string_item_t* item = (dll_string_item_t*)malloc(sizeof(dll_string_item_t));

	if (!item)
	{
		return NULL;
	}

	item->string = string;
	return item;
}



		












		
		


	

	
	
		



	


	
	





	
	




