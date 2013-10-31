/* 
 * File:   link_list.h
 * Author: 逯晓瞳
 *
 * Created on 2013年9月21日, 下午8:50
 */

#ifndef LINK_LIST_H
#define	LINK_LIST_H

#include<stdlib.h>

#define ElementType int



typedef struct NODE {
	ElementType element;
	struct NODE *next;
} Node;

typedef Node *List;

List MakeEmpty( List l );
int IsEmpty( List l );
int IsLast( List l );
List Find( List l , ElementType x );
void Delete( List l, ElementType x );
void Insert( List l, List current, ElementType x );
void CreateListForTest( List l , int num );
void TravelListForPrint( List l );






#endif	/* LINK_LIST_H */

