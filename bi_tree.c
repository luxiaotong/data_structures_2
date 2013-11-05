#include "bi_tree.h"

bi_tree create_bi_tree()
{
	bi_tree tr = (bi_tree) malloc ( sizeof(bi_tree) );
	int i = 0;
	for ( i = 0; i < 10; i ++ ) {
		tr->element = i;
		tr->left = NULL;
	}
	return ;
}

bi_tree insert_bitree(bi_tree btr, ElementType e)
{
	if ( btr == NULL ) {
		btr = (bi_tree) malloc ( sizeof(bi_tree) );
		btr->element = e;
		btr->left = NULL;btr->right = NULL;
	} else if ( e < btr->element ) {
		btr->left = insert_bitree(btr->left, e);
	} else if ( e > btr->element ) {
		btr->right = insert_bitree(btr->right, e);
	}
	return btr;
}

void print_search_tree_level_order(bi_tree btr)
{
	while ( btr != NULL || ) {
	}
	
	printf("%d", btr->element);
	
}

