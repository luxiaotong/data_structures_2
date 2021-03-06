/* 
 * File:   sorting.h
 * Author: @两荤两素三两饭
 *
 * Created on 2013年11月21日, 下午5:21
 */

#ifndef SORTING_H
#define	SORTING_H

#include<stdlib.h>

#define ELEMTYPE int


void print_array(ELEMTYPE * arr, int len);
void insertion_sort(ELEMTYPE * arr, int len);
void shell_sort(ELEMTYPE * arr, int len);

void build_heap(ELEMTYPE * arr, int len, int start);//build heap, max in top
void heap_sort(ELEMTYPE * arr, int len);
void swap_in_heap(ELEMTYPE * arr, int a, int b);
int max_in_heap(ELEMTYPE * arr, int a, int b);
void print_heap(ELEMTYPE * arr, int len);
void delete_max(ELEMTYPE * arr, int len);

void merge_sort(ELEMTYPE * arr, int len);
ELEMTYPE * merge_array(ELEMTYPE * arr, int first, int mid, int last, ELEMTYPE * tmp);

void quick_sort(ELEMTYPE * arr, int low, int high);

#endif	/* SORTING_H */

