/* 
 * File:   avl_tree.h
 * Author: 逯晓瞳
 *
 * Created on 2013年11月8日, 下午11:27
 */

#ifndef AVL_TREE_H
#define	AVL_TREE_H


#define ElementType char

#include<stdlib.h>

typedef struct AVLNODE {
	ElementType element;
	struct AVLNODE * left;
	struct AVLNODE * right;
	int height;
} AvlNode;



//avl tree
typedef AvlNode * avl_tree;

#ifndef QUEUEELEMTYPE
#define QUEUEELEMTYPE avl_tree
#endif
#include "queue.h"

avl_tree  insert_avl_tree(avl_tree avltr, ElementType e);
void print_avl_tree_level_order(avl_tree avltr);
static avl_tree make_empty(avl_tree avltr);
static avl_tree find(avl_tree avltr, ElementType e);
static avl_tree find_min(avl_tree avltr);
static avl_tree find_max(avl_tree avltr);
static avl_tree deletion(avl_tree avltr, ElementType e);

#endif	/* AVL_TREE_H */

