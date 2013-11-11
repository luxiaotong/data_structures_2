#include "avl_tree.h"

avl_tree insert_avl_tree(avl_tree avltr, ElementType e)
{
	if ( avltr == NULL ) {
		avltr = (avl_tree) malloc ( sizeof(AvlNode) );
		avltr->element = e;
		avltr->height = 0;
		avltr->left = NULL;
		avltr->right = NULL;
	} else if ( avltr->element > e ) {
		avltr->left = insert_avl_tree(avltr->left, e);
		avltr->height ++;
	} else if ( avltr->element < e ) {
		avltr->right = insert_avl_tree(avltr->right, e);
		avltr->height ++;
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
		printf("tmp:%c  qqq:%c\n", tmpavltr->element, qqq->element->element);return;
		tmpavltr = front(qqq);
		printf("%c  %c\n", tmpavltr->element, qqq->element);return;
		qqq = dequeue(qqq);
	}
	
	printf("\n");
	return;
}

static avl_tree make_empty(avl_tree avltr)
{
	if ( avltr != NULL ) {
		make_empty(avltr->left);
		make_empty(avltr->right);
		free(avltr);
	}
	return NULL;
}

static avl_tree find(avl_tree avltr, ElementType e)
{
	while ( avltr != NULL ) {
		if ( avltr->element == e ) {
			break;
		} else if ( avltr->element > e ) {
			avltr = avltr->left;
		} else { //avltr->element < e
			avltr = avltr->right;
		}
	}
	return avltr;
}

static avl_tree find_min(avl_tree avltr)
{
	while ( avltr->left != NULL ) {
		avltr = avltr->left;
	}
	return avltr;
}

static avl_tree find_max(avl_tree avltr)
{
	while ( avltr->right != NULL ) {
		avltr = avltr->right;
	}
	return avltr;
}

static avl_tree deletion(avl_tree avltr, ElementType e)
{
	
	return NULL;
}





























































/*
static avl_tree deletion(avl_tree avltr, ElementType e)
{
	avl_tree tmp_avltr = NULL;
	
	if ( avltr == NULL ) {
		return NULL;
	} else if ( avltr->element > e ) {
		avltr->left = deletion(avltr->left , e);
	} else if ( avltr->element < e ) {
		avltr->right = deletion(avltr->right, e);
	} else if ( avltr->left != NULL && avltr->right != NULL ) { //The node you want to delete has two children
		avl_tree successor_avltr = find_min(avltr->right);
		avltr->element = successor_avltr->element;
		avltr->right = deletion(avltr->right, successor_avltr->element);
	} else { //The node want to delete has one or zero child
		tmp_avltr = avltr;
		if ( avltr->left == NULL ) {
			avltr = avltr->right;
		} else if ( avltr->right == NULL ) {
			avltr = avltr->left;
		} else {
			avltr = NULL;
		}
		free(tmp_avltr);
	}
	
	return avltr;
}
*/

