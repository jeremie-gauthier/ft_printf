#include "libft.h"

int		btree_level_count(t_btree *root)
{
	int		left;
	int		right;

	if (root == NULL)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}
