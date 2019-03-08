#include "libft.h"

void	btree_insert_data(t_btree **root, void *new_data,
			int (*cmpf)(void *, void *))
{
	t_btree *root_ptr;

	if (root && *root == NULL && new_data)
		*root = btree_create_node(new_data);
	else if (root && *root && cmpf && new_data)
	{
		root_ptr = *root;
		if (cmpf(new_data, (*root)->data) >= 0)
		{
			if ((*root)->right)
				btree_insert_data(&(*root)->right, new_data, cmpf);
			else
				(*root)->right = btree_create_node(new_data);
		}
		else
		{
			if ((*root)->left)
				btree_insert_data(&(*root)->left, new_data, cmpf);
			else
				(*root)->left = btree_create_node(new_data);
		}
		root = &root_ptr;
	}
}
