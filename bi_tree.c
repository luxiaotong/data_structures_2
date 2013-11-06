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

bi_search_tree insert_bisearch_tree(bi_search_tree bschtr, ElementType e)
{
	if ( bschtr == NULL ) {
		bschtr = (bi_search_tree) malloc ( sizeof(TreeNode) );
		bschtr->element = e;
		bschtr->left = NULL;
		bschtr->right = NULL;
	} else if ( e < bschtr->element ) {
		bschtr->left = insert_bisearch_tree(bschtr->left, e);
	} else if ( e > bschtr->element ) {
		bschtr->right = insert_bisearch_tree(bschtr->right, e);
	}
	return bschtr;
}

void print_bisearch_tree_level_order(bi_search_tree bschtr)
{
	queue qqq = NULL;
	bi_search_tree tmpbschtr = bschtr;
	while ( tmpbschtr != NULL || !isempty(qqq) ) {
		if ( tmpbschtr != NULL ) {
			printf("%c", tmpbschtr->element);
			if ( tmpbschtr->left != NULL ) {
				qqq = enqueue(qqq, tmpbschtr->left);
			}
			if ( tmpbschtr->right != NULL ) {
				qqq = enqueue(qqq, tmpbschtr->right);
			}
		}
		tmpbschtr = front(qqq);
		qqq = dequeue(qqq);
	}
	
	return;
}

