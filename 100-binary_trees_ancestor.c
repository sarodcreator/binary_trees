#include "binary_trees.h"

/**
 * is_descendant - Checks if a node is a descendant of another node
 * @node: Pointer to the node to check if it's a descendant
 * @ancestor: Pointer to the node to check if it's an ancestor
 *
 * Return: 1 if node is a descendant of ancestor, 0 otherwise
 */
int is_descendant(const binary_tree_t *node, const binary_tree_t *ancestor)
{
        if (!node)
                return (0);

        if (node == ancestor)
                return (1);

        return (is_descendant(node->parent, ancestor));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 *         ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (is_descendant(second, first))
		return ((binary_tree_t *)first);
	if (is_descendant(first, second))
		return ((binary_tree_t *)second);

	return (binary_trees_ancestor(first->parent, second->parent));
}
