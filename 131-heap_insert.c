#include "binary_trees.h"

/**
 * tree_size - Function that measures the size of a binary tree
 * @tree: The tree to measure the size of
 * Return: size of tree, 0 otherwise
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_size(tree->left) + tree_size(tree->right) + 1);
}

/**
 * heap_insert - Function that inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: New node, NULL otherwise
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swp;
	int tmp, level, bit, sub, leaves, size;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = tree_size(tree);
	leaves = size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	swp = new_node;
	for (; swp->parent && (swp->n > swp->parent->n);
			swp = swp->parent)
	{
		tmp = swp->n;
		swp->n = swp->parent->n;
		swp->parent->n = tmp;
		new_node = new_node->parent;
	}
	return (new_node);
}
