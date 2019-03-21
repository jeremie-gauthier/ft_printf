#include "libft.h"

void	btree_remove_node(t_btree *node)
{
	ft_memdel(&node->data);
	ft_memdel((void*)&node);
}
