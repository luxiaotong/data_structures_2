#include "link_list.h"


int IsEmpty( List l )
{
	return (l->next == NULL);
}

int IsLast( List l )
{
	return l->next == NULL;
}

List Find( List l , ElementType x )
{
	for ( l = l->next; l != NULL; l = l->next ) {
		if ( l->element == x ) {
			break;
		}
	}
	return l;
}

void Delete( List l, ElementType x )
{
	List previous = l;
	for ( l = l->next; l != NULL; l = l->next ) {
		if ( l->element == x ) {
			previous->next = l->next;
			free(l);
			return;
		}
		previous = l;
	}
	return;
}

void Insert( List l, List current, ElementType x )
{
	List tmp_cell = (Node *) malloc( sizeof(Node) );
	if ( tmp_cell == NULL ) {
		//暂时还不知道要做什么
	}
	tmp_cell->element = x;
	tmp_cell->next = current->next;
	current->next = tmp_cell;
	return;
}
void CreateListForTest( List l, int num )
{
	int i = 0;
	for ( i = 0; i < num; i ++ ) {
		List lnext = (Node *) malloc(sizeof(Node));
		lnext->element = i + 1;
		l->next = lnext;
		l = l->next;
	}
	l->next = NULL;
}

void TravelListForPrint( List l )
{
	for ( l = l->next; l != NULL; l = l->next ) {
		printf("%d\n", l->element);
	}
}