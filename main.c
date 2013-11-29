/* 
 * File:   main.c
 * Author: 逯晓瞳
 *
 * Created on 2013年10月30日, 下午10:06
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {

#if 0 //binary search tree
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
	
#elif 0 //avl tree
	#include "avl_tree.h"
	
	int input;
	avl_tree avltr = NULL;
	
	while ( 1 ) {
		scanf("%d", &input);
		if ( input == 713 ) {
			break;
		}
		avltr = insert_avl_tree(avltr, input);
	}
	//printf("%d, %d, %d", avltr->element, avltr->left->element, avltr->right->element);
	//printf("%d, %d, %d", avltr->element, avltr->left->element, avltr->right->element);
	print_avl_tree_level_order(avltr);

#elif 1
	
	#include "sorting.h"
	
	
	/*
	//insertion sort
	int arr [] = {34, 8, 64, 51, 32, 21};
	int len = sizeof(arr) / sizeof(arr[0]);
	insertion_sort(arr, len);
	print_array(arr, len);
	*/
	
	/*
	//shell sort
	int arr [] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
	int len = sizeof(arr) / sizeof(arr[0]);
	shell_sort(arr, len);
	print_array(arr, len);
	*/
	
	/*
	//heap sort
	int arr [] = {0, 31, 41, 59, 26, 53, 58, 97};
	int len = sizeof(arr) / sizeof(arr[0]);
	print_heap(arr, len);
	heap_sort(arr, len);
	print_heap(arr, len);
	*/
	
	//merge sort
	int arr [] = {24, 13, 26, 1, 2, 27, 38, 15};
	int len = sizeof(arr) / sizeof(arr[0]);
	print_array(arr, len);
	merge_sort(arr, len);
	print_array(arr, len);
	
	
#endif
	//git fetch https://github.com/luxiaotong/data_structures_2.git
	//git reset --hard origin/master
	return (EXIT_SUCCESS);
}

