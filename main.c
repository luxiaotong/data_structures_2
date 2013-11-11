/* 
 * File:   main.c
 * Author: 逯晓瞳
 *
 * Created on 2013年10月30日, 下午10:06
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

#if 0 //binary search tree
	#include "queue.h"
	#include "bi_tree.h"
	char ch;
	bi_search_tree bschtr = NULL;
	
	while ( (ch = getchar()) != '\n' ) {
		bschtr = insert_bisearch_tree(bschtr, ch);
	}
	print_bisearch_tree_level_order(bschtr);
	
	bi_search_tree find_bschtr = find(bschtr, 'b');
	printf("find : %c\n", find_bschtr->element);
	
	bi_search_tree findmin_bschtr = find_min(bschtr);
	printf("find min : %c\n", findmin_bschtr->element);
	
	bi_search_tree findmax_bschtr = find_max(bschtr);
	printf("find max : %c\n", findmax_bschtr->element);
	
	bi_search_tree deletion_bschtr = deletion(bschtr, 'b');
	print_bisearch_tree_level_order(deletion_bschtr);
#elif 1 //avl tree
	
	#include "avl_tree.h"
	char ch;
	avl_tree avltr = NULL;
	while ( (ch = getchar()) != '\n' ) {
		avltr = insert_avl_tree(avltr, ch);
	}
	printf("%c %c %c \n", avltr->element, avltr->left->element, avltr->right->element);
	print_avl_tree_level_order(avltr);

#endif
	return (EXIT_SUCCESS);
}

