#include "avl_tree.h"

avl_tree insert_avl_tree(avl_tree avltr, ElementType e)
{
	if ( avltr == NULL ) {
		avltr = (avl_tree)malloc( sizeof(struct AvlNode) );
		avltr->element = e;
		avltr->height = 0;
		avltr->left = avltr->right = NULL;
	} else if ( avltr->element >= e ) { //to left
		avltr->left = insert_avl_tree(avltr->left, e);
		if ( height_avl_tree(avltr->left) - height_avl_tree(avltr->right) == 2 ) {
			if ( avltr->left->element >= e ) {
				avltr = single_rotate_with_left(avltr);
			} else {
				avltr = double_rotate_with_left(avltr);
			}
		}
	} else if ( avltr->element < e ) { //to right
		avltr->right = insert_avl_tree(avltr->right, e);
		avltr->height ++;
		if ( height_avl_tree(avltr->right) - height_avl_tree(avltr->left) == 2 ) {
			if ( avltr->right->element < e ) {
				avltr = single_rotate_with_right(avltr);
			} else {
				avltr = double_rotate_with_right(avltr);
			}
		}
	}
	avltr->height = fmaxf(height_avl_tree(avltr->left), height_avl_tree(avltr->right)) + 1;
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

avl_tree single_rotate_with_left(avl_tree avltr)
{
	avl_tree tmp_avltr = avltr->left;
	avltr->left = tmp_avltr->right;
	tmp_avltr->right = avltr;
	avltr->height = fmaxf(height_avl_tree(avltr->left), height_avl_tree(avltr->right)) + 1;
	tmp_avltr->height = fmaxf(height_avl_tree(tmp_avltr->left), height_avl_tree(tmp_avltr->right)) + 1;
	return tmp_avltr;
}

avl_tree single_rotate_with_right(avl_tree avltr)
{
	avl_tree tmp_avltr = avltr->right;
	avltr->right = tmp_avltr->left;
	tmp_avltr->left = avltr;
	
	avltr->height = fmaxf(height_avl_tree(avltr->left), height_avl_tree(avltr->right)) + 1;
	tmp_avltr->height = fmaxf(height_avl_tree(tmp_avltr->left), height_avl_tree(tmp_avltr->right)) + 1;
	
	return tmp_avltr;
}

avl_tree double_rotate_with_left(avl_tree avltr)
{
	avltr->left = single_rotate_with_right(avltr->left);
	avltr = single_rotate_with_left(avltr);
	return avltr;
}
avl_tree double_rotate_with_right(avl_tree avltr)
{
	avltr->right = single_rotate_with_left(avltr->right);
	avltr = single_rotate_with_right(avltr);
	return avltr;
}

void print_avl_tree_level_order(avl_tree avltr)
{
	queue avltr_q = NULL;
	int current_level_node_num = 1;
	int next_level_node_num = 0;
	while ( avltr != NULL || avltr_q != NULL ) {
		if ( avltr != NULL ) {
			current_level_node_num --;
			printf("%d", avltr->element);
			if ( avltr->left != NULL ) {
				avltr_q = avl_tree_enqueue(avltr_q, avltr->left);
				next_level_node_num ++;
			}
			if ( avltr->right != NULL ) {
				avltr_q = avl_tree_enqueue(avltr_q, avltr->right);
				next_level_node_num ++;
			}
			if ( current_level_node_num == 0 ) {
				current_level_node_num = next_level_node_num;
				next_level_node_num = 0;
				printf("\n");
			}
		}
		avltr = avl_tree_front(avltr_q);
		avltr_q = avl_tree_dequeue(avltr_q);
	}
	printf("\n");
	
	return;
}