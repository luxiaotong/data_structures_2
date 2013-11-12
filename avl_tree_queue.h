/* 
 * File:   avl_tree_queue.h
 * Author: 逯晓瞳
 *
 * Created on 2013年11月12日, 下午11:08
 */

#ifndef AVL_TREE_QUEUE_H
#define	AVL_TREE_QUEUE_H

#include <stdlib.h>
#include "avl_tree.h"

struct QueueNode {
	avl_tree element;
	struct QueueNode *next;
};

typedef struct QueueNode * queue;

//Adds an item onto the end of the queue.
queue avl_tree_enqueue( queue qqq, avl_tree qelem );

//Returns the item at the front of the queue.
avl_tree avl_tree_front( queue qqq );

//Removes the item from the front of the queue.
queue avl_tree_dequeue( queue qqq );

//True if no more items can be dequeued and there is no front item.
int avl_tree_isempty_queue( queue qqq );

//Returns the number of elements in the queue.
int avl_tree_queue_size( queue qqq );

#endif	/* AVL_TREE_QUEUE_H */

