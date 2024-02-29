#include "binary_trees.h"

/**
 * bst_insert - Function that inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: New node, NULL otherwise
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *tmp = NULL, *tmp2 = NULL;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	while (tmp)
	{
		tmp2 = tmp;
		if (value < tmp->n)
			tmp = tmp->left;

		else if (value > tmp->n)
			tmp = tmp->right;

		else if (value == tmp->n)
			return (NULL);
	}

	new_node = binary_tree_node(NULL, value);
	if (tmp2 == NULL)
		tmp2 = new_node;

	else if (value < tmp2->n)
	{
		tmp2->left = new_node;
		new_node->parent = tmp2;
	}
	else
	{
		tmp2->right = new_node;
		new_node->parent = tmp2;
	}
	return (new_node);
}
