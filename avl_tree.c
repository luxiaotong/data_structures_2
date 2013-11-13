#include "avl_tree.h"

avl_tree insert_avl_tree(avl_tree avltr, ElementType e)
{
	if ( avltr == NULL ) {
		avltr = (avl_tree)malloc( sizeof(struct AvlNode) );
		avltr->element = e;
		avltr->height = 0;
		avltr->left = NULL;
		avltr->right = NULL;
	} else if ( avltr->element >= e ) { //to left
		avltr->left = insert_avl_tree(avltr->left, e);
		avltr->height ++;
		/*
		if ( height_avl_tree(avltr->left) - height_avl_tree(avltr->right) == 2 ) {
			rotate_single_with_left(avltr);
		}
		 */
	} else if ( avltr->element < e ) { //to right
		avltr->right = insert_avl_tree(avltr->right, e);
		avltr->height ++;
		/*
		if ( height_avl_tree(avltr->right) - height_avl_tree(avltr->left) == 2 ) {
			rotate_single_with_right(avltr);
		}
		 */
	}
	return avltr;
}

int height_avl_tree(avl_tree avltr)
{
	if ( avltr == NULL ) {
		return -1;
	} else {
		return avltr->height;
	}
}

avl_tree rotate_single_with_left(avl_tree avltr)
{
	if ( avltr == NULL ) {
		return NULL;
	}
	
	avl_tree tmp_avltr = avltr->left;
	tmp_avltr->right = avltr;
	return tmp_avltr;
}

avl_tree rotate_single_with_right(avl_tree avltr)
{
	if ( avltr == NULL ) {
		return NULL;
	}
	
	avltr->left->right = avltr;
	return avltr->left;
}


void print_avl_tree_level_order(avl_tree avltr)
{
	queue avltr_q = NULL;
	while ( avltr != NULL ) {
		printf("%d", avltr->element);
		if ( avltr->left != NULL ) {
			avltr_q = avl_tree_enqueue(avltr_q, avltr->left);
		} else if ( avltr->right != NULL ) {
			avltr_q = avl_tree_enqueue(avltr_q, avltr->right);
		}
		avltr = avl_tree_front(avltr_q);
		avltr_q = avl_tree_dequeue(avltr_q);
	}
	printf("\n");
	
	return;
}