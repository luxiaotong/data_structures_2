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

#if 1
	#include "bi_tree.h"
	char ch;
	bi_tree btr = NULL;
	
	while ( (ch = getchar()) != '\n' ) {
		btr = insert_bitree(btr, ch);
	}
	printf("%c%c%c\n", btr->element, btr->right->element, btr->right->right->element);
	
#endif
	return (EXIT_SUCCESS);
}

