#include "binary_trees.h"
#include <stdlib.h>
/**
 * successor - Function that gets the next successor
 * @node: The tree to check
 * Return: min value of tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
			return (node->n);

		return (left);
	}
}

/**
 * children - Function that gets the next successor
 * @root: node tat has two children
 * Return: the value found
 */
int children(bst_t *root)
{
	int new_value = 0;

	new_value = successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 *remove_children - Function that removes a node depending of its children
 *@root: The node to remove
 *Return: value, 0 otherwise
 */
int remove_children(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;

		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;

			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;

			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (children(root));
}

/**
 * bst_remove - Function that removes a node from a BST tree
 * @root: The root of a binary tree
 * @value: The node with value to remove
 *
 * Return: Tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);

	else if (value > root->n)
		bst_remove(root->right, value);

	else if (value == root->n)
	{
		type = remove_children(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}
