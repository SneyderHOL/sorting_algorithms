#ifndef _SORT_H_
#define _SORT_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void partition(int *array, size_t size, int *vector, size_t len);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap(listint_t **list, listint_t *check, listint_t *aux);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void sift_down(int *array, size_t size, int len, size_t size1);
void make_heap(int *array, size_t size);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void print_side(int *array, size_t size);
void split_and_merge(int *array, size_t size, int *copy);
void copy_array(int *array, size_t size, int *copy);
void merge_sort(int *array, size_t size);
void comp_swap(int *array, int j, int dir);
void bitonic_merge(int *array, size_t size, int dir);
void radix_sort(int *array, size_t size);
void sort_digit(int *array, size_t size, int radix, int div);
void bitonic_up(int *array, size_t size, int dir, size_t size_f);
void bitonic_sort(int *array, size_t size);
int partition_h(int *array, size_t size, int high, size_t size_f);
void quick_sort_h(int *array, int low, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
