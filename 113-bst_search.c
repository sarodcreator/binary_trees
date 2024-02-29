#include "binary_trees.h"

/**
 * bst_search - Function that searches for a value in a binary search tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search
 *
 * Return: Search value, NULL otherwise
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (tree->n > value)
			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}
	return (NULL);
}
