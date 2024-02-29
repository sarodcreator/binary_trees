#include "binary_trees.h"

/**
 * tree_size - Function that measures the size of a binary tree
 * @tree: The tree to measure the size of
 * Return: Size of tree, 0 otherwise
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_size(tree->left) +
			tree_size(tree->right) + 1);
}

/**
 * tree_comp - Function that checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: The node index to check
 * @size: Number of nodes in the tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_comp(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (tree_comp(tree->left, 2 * index + 1, size) &&
			tree_comp(tree->right, 2 * index + 2, size));
}

/**
 * is_complete - Function that checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = tree_size(tree);

	return (tree_comp(tree, 0, size));
}

/**
 * is_mbh - Function that checks if b-tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if valid Max Binary Heap, 0 otherwise
 */
int is_mbh(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);

	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (is_mbh(tree->left) && is_mbh(tree->right));
}

/**
 * binary_tree_is_heap - Func that checks if b-tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_mbh(tree));
}
