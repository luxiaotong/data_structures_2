/* 
 * File:   queue.h
 * Author: @两荤两素三两饭
 *
 * include前请先#define QUEUEELEMTYPE
 * Created on 2013年11月6日, 下午2:40
 */

#ifndef QUEUE_H
#define	QUEUE_H


#include <stdlib.h>

#ifndef QUEUEELEMTYPE
#define QUEUEELEMTYPE avl_tree
#endif


typedef struct QUEUENODE {
	QUEUEELEMTYPE element;
	struct QUEUENODE *next;
} QueueNode;

typedef QueueNode * queue;

//Adds an item onto the end of the queue.
queue enqueue( queue qqq, QUEUEELEMTYPE qelem );

//Returns the item at the front of the queue.
QUEUEELEMTYPE front( queue qqq );

//Removes the item from the front of the queue.
queue dequeue( queue qqq );

//True if no more items can be dequeued and there is no front item.
int isempty( queue qqq );

//True if no more items can be enqueued.
int isfull( queue qqq );

//Returns the number of elements in the queue.
int getsize( queue qqq );



#endif	/* QUEUE_H */

