/* 
 * File:   avl_tree.h
 * Author: 逯晓瞳
 *
 * Created on 2013年11月12日, 下午10:29
 */

#ifndef AVL_TREE_H
#define	AVL_TREE_H

#define ElementType int
#include<stdlib.h>

struct AvlNode {
	ElementType element;
	struct AvlNode * left;
	struct AvlNode * right;
	int height;
};
typedef struct AvlNode * avl_tree;

avl_tree  insert_avl_tree(avl_tree avltr, ElementType e);
void print_avl_tree_level_order(avl_tree avltr);
avl_tree deletion_avl_tree(avl_tree avltr, ElementType e);

#include "avl_tree_queue.h"

#endif	/* AVL_TREE_H */

