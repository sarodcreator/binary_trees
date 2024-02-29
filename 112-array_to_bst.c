#include "binary_trees.h"

/**
 * array_to_bst - Function that builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: No. of elements in the array
 *
 * Return: New node, 0 otherwise
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *b_tree = NULL;
	unsigned int i = 0;

	while (i < size)
	{
		bst_insert(&b_tree, array[i]);
		i++;
	}

	return (b_tree);
}
