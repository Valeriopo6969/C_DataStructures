#include "linked_lists.h"
#include <stdio.h>
 list_node_t* ll_list_get_tail(list_node_t**head)
{
	 list_node_t* current_node = *head;
	 list_node_t* last_node = NULL;

	while (current_node)
	{
		last_node = current_node;
		current_node = current_node->next;
	}

	return last_node;
};

 list_node_t* ll_list_pop(list_node_t** head)
{
	list_node_t* current_node = *head;
	if (!current_node)
	{
		return NULL;
	}

	*head = (*head)->next;
	current_node->next = NULL;

	return current_node;
}

list_node_t* ll_list_append(list_node_t** head,  list_node_t* item)
{
	if (!item) return NULL;

	list_node_t* tail = ll_list_get_tail(head);
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

list_node_t* ll_list_remove(list_node_t** head, list_node_t* item)
{
	if (!item || !*head) return NULL;

	list_node_t* current_node = *head;

	if (current_node == item)
	{
		*head = (*head)->next;
		current_node->next = NULL;
		return current_node;
	}

	list_node_t* last_node = current_node;
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

int ll_list_reverse(list_node_t** head)
{
	if (!*head) return 0;

	list_node_t* current_node = *head;
	list_node_t* last_node = NULL;
	list_node_t* next_node = NULL;

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

string_item_t* ll_string_item_new(const char* string)
{
	string_item_t* item = malloc(sizeof(string_item_t));
	if (!item)
	{
		return NULL;
	}
	item->string = string;
	return item;
}


		


	
	

	

	
	
	

	

	


