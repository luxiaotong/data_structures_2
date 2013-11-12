#include "avl_tree.h"

avl_tree insert_avl_tree(avl_tree avltr, ElementType e)
{
	if ( avltr == NULL ) {
		avltr = (avl_tree)malloc( sizeof(struct AvlNode) );
		avltr->element = e;
		avltr->height = 0;
		avltr->left = NULL;
		avltr->right = NULL;
	}
	return avltr;
}
