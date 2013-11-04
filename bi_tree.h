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

typedef TreeNode * bi_tree;

bi_tree create_bi_tree();
bi_tree  insert_bitree(bi_tree btr, ElementType e);
void print_bitree_strata_seqeunce(bi_tree btr);




#endif	/* BI_TREE_H */

