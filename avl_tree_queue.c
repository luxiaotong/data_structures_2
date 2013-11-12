#include "avl_tree_queue.h"

//Adds an item onto the end of the queue.
queue avl_tree_enqueue( queue qqq, avl_tree qelem )
{
	if ( avl_tree_isempty_queue(qqq) ) {
		qqq = (queue) malloc( sizeof(struct QueueNode) );
		qqq->element = qelem;
		qqq->next = NULL;
		return qqq;
	}
	
	queue tmpqqq = qqq;
	while ( !avl_tree_isempty_queue(tmpqqq->next) ) {
		tmpqqq = tmpqqq->next;
	}
	
	queue qnode = malloc( sizeof(struct QueueNode) );
	qnode->element = qelem;
	qnode->next = NULL;
	
	tmpqqq->next = qnode;
	
	return qqq;
}

//Returns the item at the front of the queue.
avl_tree avl_tree_front( queue qqq )
{
	if ( avl_tree_isempty_queue(qqq) ) {
		return NULL;
	}
	
	return qqq->element;
	
}

//Removes the item from the front of the queue.
queue avl_tree_dequeue( queue qqq )
{
	if ( avl_tree_isempty_queue(qqq) ) {
		return NULL;
	}
	
	queue tmpqqq = qqq;
	qqq = qqq->next;
	free(tmpqqq);
	
	return qqq;
}

//True if no more items can be dequeued and there is no front item.
int avl_tree_isempty_queue( queue qqq )
{
	if ( qqq == NULL ) {
		return 1;
	} else {
		return 0;
	}
}

//Returns the number of elements in the queue.
int avl_tree_queue_size( queue qqq )
{
	int count = 0;
	if ( avl_tree_isempty_queue(qqq) ) {
		return 0;
	}
	
	while ( !avl_tree_isempty_queue(qqq) ) {
		count = count + 1;
	}
	
	return count;
}

