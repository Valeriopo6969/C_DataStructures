#include "doubly_linked_lists.h"


#pragma region tests_utils
const int seed = 555;

int custom_random(int n)
{
	int limit;
	int r;
	limit = RAND_MAX - (RAND_MAX % n);

	while ((r = rand()) >= limit);

	return r % n;
}
#pragma endregion

dll_node* dll_append(dll_node** head, dll_node* item)
{
	if (!item) return NULL;

	dll_node* tail = dll_get_tail(head);

	if (!tail)
	{
		*head = item;
	}
	else
	{
		tail->next = item;
	}
	item->prev = tail;
	item->next = NULL;
	return item;
}

dll_node* dll_get_tail(dll_node** head) {

	dll_node* current_node = *head;
	dll_node* last_node = NULL;

	while (current_node)
	{
		last_node = current_node;
		current_node = current_node->next;
	}

	return last_node;
}

dll_node* dll_list_pop(dll_node** head)
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

dll_node* dll_list_remove(dll_node** head, dll_node* item)
{
	if (!head || !item) return NULL;

	//if first item
	if (*head == item)
		*head = item->next;

	if (item->next)
		item->next->prev = item->prev;

	if (item->prev)
		item->prev->next = item->next;

	item->next = NULL;
	item->prev = NULL;

	return item;
}

dll_node* dll_get_node_at(dll_node** head, int index)
{
	dll_node* current_node = *head;
	
	while (current_node && index>0)
	{
		index--;
		current_node = current_node->next;
	}

	if (index > 0) return NULL; //exceeded list max length
	return current_node; 
}
		
int dll_list_get_length(dll_node** head)
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

int dll_list_shuffle(dll_node** head)
{
	if (!head) return 0;
	
	int index = dll_list_get_length(head);
	
	while (index > 0)
	{
		int node_at = custom_random(index);						//using a 'fake' random method to generate testable result
		dll_node* item = dll_get_node_at(head, node_at);		// taking a node at random valid index
		dll_node* item_removed = dll_list_remove(head, item);	// removing it from the doubly linked list...
		dll_append(head, item_removed);							// ...then append it to the same list

		index--;												//decreasing the index so next time won't shuffle an already shuffled node
	}

	return 1;
}

dll_node* dll_insert_after(dll_node* node, dll_node* item_to_insert)
{
	if (!node) return NULL; //u can't access a NULL pointer

	item_to_insert->next = node->next;

	node->next = item_to_insert;

	item_to_insert->prev = node;

	if (item_to_insert->next)
		item_to_insert->next->prev = item_to_insert;

	return item_to_insert;
}

dll_node* dll_insert_before(dll_node* node, dll_node* item_to_insert)
{
	if (!node) return NULL; //u can't access a NULL pointer

	item_to_insert->prev = node->prev;

	node->prev = item_to_insert;

	item_to_insert->next = node;

	if (item_to_insert->prev)
		item_to_insert->prev->next = item_to_insert;

	return item_to_insert;
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





		
		


	

	
	
		



	


	
	





	
	




