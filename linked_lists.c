#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define TEST_DEBUG
#include "linked_lists.h"

void ll_list_free(ll_node_t** head)
{
	ll_string_item_t* to_free;
	while ((to_free = ll_pop(head)))
	{
		free(to_free);
		to_free = NULL;
		
	}
}

 ll_node_t* ll_get_tail(ll_node_t**head)
{
	 ll_node_t* current_node = *head;
	 ll_node_t* last_node = NULL;

	while (current_node)
	{
		last_node = current_node;
		current_node = current_node->next;
	}

	return last_node;
};

 ll_node_t* ll_pop(ll_node_t** head)
{
	ll_node_t* current_node = *head;
	if (!current_node)
	{
		return NULL;
	}

	*head = (*head)->next;
	current_node->next = NULL;

	return current_node;
}

ll_node_t* ll_append(ll_node_t** head,  ll_node_t* item)
{
	if (!item) return NULL;

	ll_node_t* tail = ll_get_tail(head);
	if (!tail)
	{
		*head = item;
	}
	else
	{
		tail->next = item;
	}

	item->next = NULL;
	return item;
}

ll_node_t* ll_remove(ll_node_t** head, ll_node_t* item)
{
	if (!item || !*head) return NULL;

	ll_node_t* current_node = *head;

	if (current_node == item)
	{
		*head = (*head)->next;
		current_node->next = NULL;
		return current_node;
	}

	ll_node_t* last_node = current_node;
	current_node = current_node->next;

	while (current_node)
	{
		if (current_node == item)
		{
			last_node->next = current_node->next;
			item->next = NULL;
			return item;
		}

		last_node = current_node;
		current_node = current_node->next;
	}
	return NULL;
}

int ll_list_reverse(ll_node_t** head)
{
	if (!*head) return 0;

	ll_node_t* current_node = *head;
	ll_node_t* last_node = NULL;
	ll_node_t* next_node = NULL;

	while (current_node)
	{
		next_node = current_node->next;
		current_node->next = last_node;
		last_node = current_node;
		current_node = next_node;
	}

	*head = last_node;

	return 1;
}

ll_string_item_t* ll_string_item_new(const char* string)
{
	ll_string_item_t* item = malloc(sizeof(ll_string_item_t));
	if (!item)
	{
		return NULL;
	}
	item->string = string;
	return item;
}


		


	
	

	

	
	
	

	

	


