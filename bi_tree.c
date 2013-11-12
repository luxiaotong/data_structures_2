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
	int node_in_current_level = 1;
	int node_in_next_level = 0;
	
	printf("\ntree:\n");
	while ( tmpbschtr != NULL || !isempty(qqq) ) {
		if ( tmpbschtr != NULL ) {
			printf("%c", tmpbschtr->element);
			if ( tmpbschtr->left != NULL ) {
				qqq = enqueue(qqq, tmpbschtr->left);
				node_in_next_level ++;
			}
			if ( tmpbschtr->right != NULL ) {
				qqq = enqueue(qqq, tmpbschtr->right);
				node_in_next_level ++;
			}
			node_in_current_level --;
			if ( node_in_current_level == 0 ) {
				printf("\n");
				node_in_current_level = node_in_next_level;
				node_in_next_level = 0;
			}
		}
		tmpbschtr = front(qqq);
		qqq = dequeue(qqq);
	}
	
	printf("\n");
	return;
}

bi_search_tree make_empty(bi_search_tree bschtr)
{
	if ( bschtr != NULL ) {
		make_empty(bschtr->left);
		make_empty(bschtr->right);
		free(bschtr);
	}
	return NULL;
}

bi_search_tree find(bi_search_tree bschtr, ElementType e)
{
	while ( bschtr != NULL ) {
		if ( bschtr->element == e ) {
			break;
		} else if ( bschtr->element > e ) {
			bschtr = bschtr->left;
		} else { //bschtr->element < e
			bschtr = bschtr->right;
		}
	}
	return bschtr;
}

bi_search_tree find_min(bi_search_tree bschtr)
{
	while ( bschtr->left != NULL ) {
		bschtr = bschtr->left;
	}
	return bschtr;
}

bi_search_tree find_max(bi_search_tree bschtr)
{
	while ( bschtr->right != NULL ) {
		bschtr = bschtr->right;
	}
	return bschtr;
}


bi_search_tree deletion(bi_search_tree bschtr, ElementType e)
{
	bi_search_tree tmp_bschtr = NULL;
	if ( bschtr == NULL ) {
		return NULL;
	} else if ( bschtr->element > e ) {
		bschtr->left = deletion(bschtr->left, e);
	} else if ( bschtr->element < e ) {
		bschtr->right = deletion(bschtr->right, e);
	} else if ( bschtr->left != NULL && bschtr->right != NULL ) { //two children
		tmp_bschtr = find_min(bschtr->right);
		bschtr->element = tmp_bschtr->element;
		bschtr->right = deletion(bschtr->right, tmp_bschtr->element);
	} else { //one or zero child
		tmp_bschtr = bschtr;
		if ( bschtr->left != NULL ) {
			bschtr = bschtr->left;
		} else if ( bschtr->right != NULL ) {
			bschtr = bschtr->right;
		} else {
			bschtr = NULL;
		}
		free(tmp_bschtr);
	}
	return bschtr;
}

avl_tree insert_avl_tree(avl_tree avltr, ElementType e)
{
	if ( avltr == NULL ) {
		avltr = (avl_tree) malloc ( sizeof(TreeNode) );
		avltr->element = e;
		avltr->left = NULL;
		avltr->right = NULL;
	} else if ( e < avltr->element ) {
		avltr->left = insert_avl_tree(avltr->left, e);
	} else if ( e > avltr->element ) {
		avltr->right = insert_avl_tree(avltr->right, e);
	}
	return avltr;
}

void print_avl_tree_level_order(avl_tree avltr)
{
	queue qqq = NULL;
	avl_tree tmpavltr = avltr;
	int node_in_current_level = 1;
	int node_in_next_level = 0;
	
	printf("\ntree:\n");
	while ( tmpavltr != NULL || !isempty(qqq) ) {
		if ( tmpavltr != NULL ) {
			printf("%c", tmpavltr->element);
			if ( tmpavltr->left != NULL ) {
				qqq = enqueue(qqq, tmpavltr->left);
				node_in_next_level ++;
			}
			if ( tmpavltr->right != NULL ) {
				qqq = enqueue(qqq, tmpavltr->right);
				node_in_next_level ++;
			}
			node_in_current_level --;
			if ( node_in_current_level == 0 ) {
				printf("\n");
				node_in_current_level = node_in_next_level;
				node_in_next_level = 0;
			}
		}
		tmpavltr = front(qqq);
		qqq = dequeue(qqq);
	}
	
	printf("\n");
	return;
}

avl_tree avl_tree_deletion(avl_tree avltr, ElementType e)
{
	avl_tree tmp_avltr = NULL;
	if ( avltr == NULL ) {
		return NULL;
	} else if ( avltr->element > e ) {
		avltr->left = deletion(avltr->left, e);
	} else if ( avltr->element < e ) {
		avltr->right = deletion(avltr->right, e);
	} else if ( avltr->left != NULL && avltr->right != NULL ) { //two children
		tmp_avltr = find_min(avltr->right);
		avltr->element = tmp_avltr->element;
		avltr->right = deletion(avltr->right, tmp_avltr->element);
	} else { //one or zero child
		tmp_avltr = avltr;
		if ( avltr->left != NULL ) {
			avltr = avltr->left;
		} else if ( avltr->right != NULL ) {
			avltr = avltr->right;
		} else {
			avltr = NULL;
		}
		free(tmp_avltr);
	}
	return avltr;
}
