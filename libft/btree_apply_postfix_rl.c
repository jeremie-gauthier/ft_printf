#include "libft.h"

void	btree_apply_postfix_rl(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->right)
			btree_apply_prefix_rl(root->right, applyf);
		if (root->left)
			btree_apply_prefix_rl(root->left, applyf);
		if (root->data)
			applyf(root->data);
	}
}
