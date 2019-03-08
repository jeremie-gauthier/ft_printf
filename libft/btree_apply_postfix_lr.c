#include "libft.h"

void	btree_apply_postfix_lr(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->left)
			btree_apply_prefix_lr(root->left, applyf);
		if (root->right)
			btree_apply_prefix_lr(root->right, applyf);
		if (root->data)
			applyf(root->data);
	}
}
