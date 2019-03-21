#include "libft.h"

void	btree_apply_infix_lr(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->left)
			btree_apply_prefix_lr(root->left, applyf);
		if (root->data)
			applyf(root->data);
		if (root->right)
			btree_apply_prefix_lr(root->right, applyf);
	}
}
