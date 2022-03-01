#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define TEST_DEBUG
#include "linked_lists.h"

void ll_list_free(ll_node** head)
{
	ll_string_item* to_free;
	while ((to_free = ll_pop(head)))
	{
		free(to_free);
		to_free = NULL;
		
	}
}

 ll_node* ll_get_tail(ll_node**head)
{
	 ll_node* current_node = *head;
	 ll_node* last_node = NULL;

	while (current_node)
	{
		last_node = current_node;
		current_node = current_node->next;
	}

	return last_node;
};

 ll_node* ll_pop(ll_node** head)
{
	ll_node* current_node = *head;
	if (!current_node)
	{
		return NULL;
	}

	*head = (*head)->next;
	current_node->next = NULL;

	return current_node;
}

ll_node* ll_append(ll_node** head,  ll_node* item)
{
	if (!item) return NULL;

	ll_node* tail = ll_get_tail(head);
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

ll_node* ll_remove(ll_node** head, ll_node* item)
{
	if (!item || !*head) return NULL;

	ll_node* current_node = *head;

	if (current_node == item)
	{
		*head = (*head)->next;
		current_node->next = NULL;
		return current_node;
	}

	ll_node* last_node = current_node;
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

int ll_list_reverse(ll_node** head)
{
	if (!*head) return 0;

	ll_node* current_node = *head;
	ll_node* last_node = NULL;
	ll_node* next_node = NULL;

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

ll_string_item* ll_string_item_new(const char* string)
{
	ll_string_item* item = malloc(sizeof(ll_string_item));
	if (!item)
	{
		return NULL;
	}
	item->string = string;
	return item;
}


		


	
	

	

	
	
	

	

	


