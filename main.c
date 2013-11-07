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

#if 1 //binary search tree
	#include "bi_tree.h"
	char ch;
	bi_search_tree bschtr = NULL;
	
	while ( (ch = getchar()) != '\n' ) {
		bschtr = insert_bisearch_tree(bschtr, ch);
	}
	print_bisearch_tree_level_order(bschtr);
	
	bi_search_tree find_bschtr = find(bschtr, 'b');
	printf("%c\n", find_bschtr->element);
	
	

#endif
	return (EXIT_SUCCESS);
}

