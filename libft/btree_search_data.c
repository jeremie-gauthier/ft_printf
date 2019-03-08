#include "libft.h"

void	*btree_search_data(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	t_btree	*ret;

	ret = NULL;
	if (root && data_ref && cmpf)
	{
		if (root->left)
			ret = btree_search_data(root->left, data_ref, cmpf);
		if (cmpf(data_ref, root->data) == 1)
			return (root);
		if (root->right)
			ret = btree_search_data(root->right, data_ref, cmpf);
	}
	return (ret);
}
