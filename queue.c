#include "queue.h"

//Adds an item onto the end of the queue.
queue enqueue( queue qqq, QUEUEELEMTYPE qelem )
{
	if ( isempty(qqq) ) {
		qqq = (queue) malloc( sizeof(QueueNode) );
		qqq->element = qelem;
		qqq->next = NULL;
		return qqq;
	}
	
	queue tmpqqq = qqq;
	while ( isempty(tmpqqq->next) ) {
		tmpqqq = tmpqqq->next;
	}
	
	queue qnode = malloc( sizeof(QueueNode) );
	qnode->element = qelem;
	qnode->next = NULL;
	
	tmpqqq->next = qnode;
	
	return qqq;
}

//Returns the item at the front of the queue.
QUEUEELEMTYPE front( queue qqq )
{
	if ( isempty(qqq) ) {
		return NULL;
	}
	
	return qqq->element;
	
}

//Removes the item from the front of the queue.
queue dequeue( queue qqq )
{
	if ( isempty(qqq) ) {
		return NULL;
	}
	
	queue tmpqqq = qqq;
	qqq = qqq->next;
	free(tmpqqq);
	
	return qqq;
}

//True if no more items can be dequeued and there is no front item.
int isempty( queue qqq )
{
	if ( qqq == NULL ) {
		return 1;
	} else {
		return 0;
	}
}

//Returns the number of elements in the queue.
int getsize( queue qqq )
{
	int count = 0;
	if ( isempty(qqq) ) {
		return 0;
	}
	
	while ( !isempty(qqq) ) {
		count = count + 1;
	}
	
	return count;
}
