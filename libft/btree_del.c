#include "libft.h"

void	btree_del(t_btree **root, int data_is_malloc)
{
	if (root && *root)
	{
		if ((*root)->left)
			btree_del(&(*root)->left, data_is_malloc);
		if ((*root)->right)
			btree_del(&(*root)->right, data_is_malloc);
		if (data_is_malloc == 1)
			ft_memdel(&(*root)->data);
		ft_memdel((void**)root);
	}	
}
