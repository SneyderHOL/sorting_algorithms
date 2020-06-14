#include "sort.h"

/**
 * insertion_sort_list - 
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *check, *aux, *back;

	if (list == NULL || *list == NULL)
		return;

	check = *list;
	while (check->next != NULL)
	{
		if (check->n > check->next->n)
		{
			aux = check->next;
			aux->prev = check->prev;
			check->next = aux->next;
			if (aux->next != NULL)
				aux->next->prev = check;
			check->prev = aux;
			aux->next = check;
			aux->prev->next = aux;
			if (check == *list)
				*list = aux;
			back = *list;	
			print_list(back);
			while (aux->prev != NULL)
			{
				if (aux->n < aux->prev->n)
				{
					back = aux->prev;
					aux->prev = back->prev;
					back->next = aux->next;
					aux->next->prev = back;
					aux->next = back;
					back->prev = aux;
					if (aux->prev != NULL)
						aux->prev->next = aux;
					if (back == *list)
						*list = aux;
					back = *list;
					print_list(back);
				}
				else
					break;				
			}
		
		}
		else
			check = check->next;
	}	

}
