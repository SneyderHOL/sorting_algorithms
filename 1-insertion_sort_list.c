#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of integers ascending order
 * @list: double linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *check = NULL, *aux = NULL, *back = NULL;

	if (list == NULL || *list == NULL)
		return;

	check = *list;
	while (check->next != NULL)
	{
		if (check->n > check->next->n)
		{
			aux = check->next;
			swap(list, check, aux);
			while (aux->prev != NULL)
			{
				if (aux->n < aux->prev->n)
				{
					back = aux->prev;
					swap(list, back, aux);
				}
				else
					break;
			}

		}
		else
			check = check->next;
	}

}
/**
 *swap - swaps two noded in double linked list
 *@list: double linked list to be sorted
 *@check: node to move forward
 *@aux: node to move backward
 *Return: void
 */
void swap(listint_t **list, listint_t *check, listint_t *aux)
{
	aux->prev = check->prev;
	check->next = aux->next;
	if (aux->next != NULL)
		aux->next->prev = check;
	check->prev = aux;
	aux->next = check;
	if (aux->prev != NULL)
		aux->prev->next = aux;
	if (check == *list)
		*list = aux;
	print_list(*list);
}
