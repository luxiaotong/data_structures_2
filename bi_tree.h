/* 
 * File:   bi_tree.h
 * Author: 逯晓瞳
 *
 * Created on 2013年11月2日, 下午9:43
 */

#ifndef BI_TREE_H
#define	BI_TREE_H

#define ElementType char

#include<stdlib.h>

typedef struct TREENODE {
	ElementType element;
	struct TREENODE * left;
	struct TREENODE * right;
} TreeNode;

//binary tree
typedef TreeNode * bi_tree;

bi_tree create_bi_tree();

//binary search tree
typedef TreeNode * bi_search_tree;

bi_search_tree  insert_bisearch_tree(bi_search_tree bschtr, ElementType e);
void print_bi_tree_level_order(bi_search_tree bschtr);
bi_search_tree make_empty(bi_search_tree bschtr);
bi_search_tree find(bi_search_tree bschtr, ElementType e);
bi_search_tree find_min(bi_search_tree bschtr);
bi_search_tree find_max(bi_search_tree bschtr);
bi_search_tree deletion(bi_search_tree bschtr, ElementType e);

//avl tree
typedef TreeNode * avl_tree;

avl_tree  insert_avl_tree(avl_tree avltr, ElementType e);
void print_avl_tree_level_order(avl_tree avltr);
avl_tree avl_tree_deletion(avl_tree avltr, ElementType e);

#include "queue.h"


#endif	/* BI_TREE_H */

