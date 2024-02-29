#include "binary_trees.h"

/**
 * array_to_heap - Function that builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: Root node of created Binary Heap, NULL otherwise
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root_node = NULL;
	unsigned int i = 0;

	while (i < size)
	{
		heap_insert(&root_node, array[i]);
		i++;
	}

	return (root_node);
}

