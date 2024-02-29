#include "binary_trees.h"

/**
 * tree_height - Function that measures the height of a binary tree
 * @tree: The tree to measure the height of
 * Return: height of tree, 0 otherwise
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + tree_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * check_avl - Function that finds if a binary tree is an avl
 * @tree: Pointer to the root node of the tree
 * @min: The minimum value
 * @max: The maximum value
 *
 * Return: 1 if tree is avl, 0 otherwise
 */
int check_avl(const binary_tree_t *tree, int min, int max)
{
	int left_child, right_child;

	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_child = tree->left ? 1 + tree_height(tree->left) : 0;
	right_child = tree->right ? 1 + tree_height(tree->right) : 0;

	if (abs(left_child - right_child) > 1)
		return (0);

	return (check_avl(tree->left, min, tree->n - 1) &&
			check_avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Function that finds if a binary tree is an avl
 * @tree: Pointer to the root node of the tree
 * Return: 1 if tree is avl, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_avl(tree, INT_MIN, INT_MAX));
}
