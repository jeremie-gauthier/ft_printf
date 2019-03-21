#include "libft.h"

t_btree     *btree_create_node(void *data)
{
    t_btree     *node;

    if (!(node = (t_btree*)malloc(sizeof(*node))))
        return (NULL);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
