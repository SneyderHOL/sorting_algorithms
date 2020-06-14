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
			swap_forward(list, check, aux);
			while (aux->prev != NULL)
			{
				if (aux->n < aux->prev->n)
				{
					back = aux->prev;
					swap_backwards(list, back, aux);
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
 *swap_forward - moves node forward
 *@list: double linked list to be sorted
 *@check: element to start comparison
 *@aux: element to compare in list
 *Return: void
 */
void swap_forward(listint_t **list, listint_t *check, listint_t *aux)
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

/**
 *swap_backwards - moves
 *@list: double linked list to be sorted
 *@back: element to start comparison
 *@aux: element to compare in list
 *Return: void
 */
void swap_backwards(listint_t **list, listint_t *back, listint_t *aux)
{
	aux->prev = back->prev;
	back->next = aux->next;
	if (aux->next != NULL)
		aux->next->prev = back;
	aux->next = back;
	back->prev = aux;
	if (aux->prev != NULL)
		aux->prev->next = aux;
	if (back == *list)
		*list = aux;
	print_list(*list);
}
