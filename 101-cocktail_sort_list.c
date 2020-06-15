#include "sort.h"

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * ascending order using Cocktail shaker sort algorithm
 * @list: pointer to the doubly linked list to sort
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *aux = NULL, *s_node = NULL, *first = NULL, *last = NULL;
	int swaped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	aux = *list;
	s_node = *list;
	do {
		while (aux->next != last)
		{
			if (aux->n > aux->next->n)
			{
				s_node = aux->next;
				swap(list, aux, s_node);
				swaped = 1;
			}
			else
				aux = aux->next;
		}
		last = aux;
		if (swaped == 0)
			break;
		swaped = 0;
		while (aux->prev != first)
		{
			if (aux->n < aux->prev->n)
			{
				s_node = aux->prev;
				swap(list, s_node, aux);
				swaped = 1;
			}
			else
				aux = aux->prev;
		}
	} while (swaped);
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
