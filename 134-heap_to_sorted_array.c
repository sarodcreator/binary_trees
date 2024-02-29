#include "binary_trees.h"

/**
 * bin_tree_size - Function that measures sum of heights of a binary tree
 * @tree: Pointer to root node of tree to measure height
 * Return: Height, 0 otherwise
 */
size_t bin_tree_size(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + bin_tree_size(tree->left);

	if (tree->right)
		right_height = 1 + bin_tree_size(tree->right);

	return (left_height + right_height);
}

/**
 * heap_to_sorted_array - Func that converts BMH to sorted array of integers
 * @heap: Pointer to root node of heap to convert
 * @size: The address to store size of array
 *
 * Return: Generated array, NULL otherwise
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL, i;

	if (!heap || !size)
		return (NULL);

	*size = bin_tree_size(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
