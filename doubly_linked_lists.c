#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//#define TEST_DEBUG
#include "doubly_linked_lists.h"

void dll_list_free(dll_node** head)
{
	dll_string_item* to_free;
	while ((to_free = dll_pop(head)))
	{
		free(to_free);
		to_free = NULL;
	}
}

dll_node* dll_append(dll_node** head, dll_node* node)
{
	if (!node) return NULL;

	dll_node* tail = dll_get_tail(head);

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

dll_node* dll_get_tail(dll_node** head) {

	dll_node* current_node = *head;
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

dll_node* dll_pop(dll_node** head)
{
	dll_node* current_node = *head;
	if (!current_node)
	{
		return NULL;
	}

	*head = (*head)->next;
	current_node->next = NULL;

	return current_node;
}

dll_node* dll_remove(dll_node** head, dll_node* node)
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

dll_node* dll_get_node_at(dll_node** head, int index)
{
	dll_node* current_node = *head;
	if (!current_node)
	{
		return NULL;
	}

	while (current_node && index > 0)
	{
		index--;
		current_node = current_node->next;
	}

	if (index > 0) return NULL; //exceeded list max length
	return current_node;
}

int dll_get_length(dll_node** head)
{
	dll_node* current_node = *head;
	int counter = 0;

	while (current_node)
	{
		counter++;

		current_node = current_node->next;
	}

	return counter;
}

int dll_shuffle(dll_node** head)
{
	if (!(*head)) return 0;

	int index = dll_get_length(head);

	while (index > 0)
	{
		int node_at = custom_random(index);						//using a 'fake' random method to generate testable result
		dll_node* item = dll_get_node_at(head, node_at);		// taking a node at random valid index
		dll_node* item_removed = dll_remove(head, item);		// removing it from the list...
		dll_append(head, item_removed);							// ...then append it to the same list

		index--;												//decreasing the index value so next time won't shuffle an already shuffled node
	}

	return 1;
}

dll_node* dll_insert_after(dll_node* node, dll_node* node_to_insert)
{
	if (!node) return NULL; //u can't access a NULL pointer

	node_to_insert->next = node->next;

	node->next = node_to_insert;

	node_to_insert->prev = node;

	if (node_to_insert->next)
		node_to_insert->next->prev = node_to_insert;

	return node_to_insert;
}

dll_node* dll_insert_before(dll_node* node, dll_node* node_to_insert)
{
	if (!node) return NULL; //u can't access a NULL pointer

	node_to_insert->prev = node->prev;

	node->prev = node_to_insert;

	node_to_insert->next = node;

	if (node_to_insert->prev)
		node_to_insert->prev->next = node_to_insert;

	return node_to_insert;
}

dll_string_item* dll_string_item_new(const char* string)
{
	dll_string_item* item = (dll_string_item*)malloc(sizeof(dll_string_item));

	if (!item)
	{
		return NULL;
	}

	item->string = string;
	return item;
}



		












		
		


	

	
	
		



	


	
	





	
	




