#include "binary_trees.h"
#include "0-binary_tree_node.c"

/**
 * height - Function that measures the height of a binary tree
 * @tree: Pointer to root node of tree to measure height
 * Return: Height, 0 otherwise
 */
size_t height(const heap_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + height(tree->left);

	if (tree->right)
		right_height = 1 + height(tree->right);

	if (left_height > right_height)
		return (left_height);

	return (right_height);
}

/**
 * do_heap - Function that heapifies max binary heap
 * @root: Pointer to binary heap
 * Return: None
 */
void do_heap(heap_t *root)
{
	heap_t *tmp_left, *tmp_right;
	int value;

	if (!root)
		return;

	tmp_left = root;

	while (1)
	{
		if (!tmp_left->left)
			break;

		if (!tmp_left->right)
			tmp_right = tmp_left->left;
		else
		{
			if (tmp_left->left->n > tmp_left->right->n)
				tmp_right = tmp_left->left;
			else
				tmp_right = tmp_left->right;
		}
		if (tmp_left->n > tmp_right->n)
			break;

		value = tmp_left->n;
		tmp_left->n = tmp_right->n;
		tmp_right->n = value;
		tmp_left = tmp_right;
	}
}

/**
 * pre_order - Function that visits a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @node: The last note in preorder traverse
 * @height: The tree height
 *
 * Return: None
 */
void pre_order(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;

	height--;

	pre_order(tree->left, node, height);
	pre_order(tree->right, node, height);
}

/**
 * heap_extract - Function that extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root of heap
 * Return: Value, 0 otherwise
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *max_h, *new_node;

	if (!root || !*root)
		return (0);

	max_h = *root;
	value = max_h->n;
	if (!max_h->left && !max_h->right)
	{
		*root = NULL;
		free(max_h);
		return (value);
	}

	pre_order(max_h, &new_node, height(max_h));

	max_h->n = new_node->n;
	if (new_node->parent->right)
		new_node->parent->right = NULL;
	else
		new_node->parent->left = NULL;

	free(new_node);
	do_heap(max_h);
	*root = max_h;
	return (value);
}
