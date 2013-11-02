/* 
 * File:   bi_tree.h
 * Author: 逯晓瞳
 *
 * Created on 2013年11月2日, 下午9:43
 */

#ifndef BI_TREE_H
#define	BI_TREE_H

#define ElementType int

#include<stdlib.h>

typedef struct TREENODE {
	ElementType element;
	struct TREENODE * left;
	struct TREENODE * right;
} TreeNode;

typedef TreeNode * bi_tree;

bi_tree create_bi_tree();
void print_bitree_strata_seqeunce(bi_tree tr);




#endif	/* BI_TREE_H */

