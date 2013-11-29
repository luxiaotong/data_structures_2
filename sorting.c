#include "sorting.h"



void print_array(ELEMTYPE * arr, int len)
{
	int i = 0;
	for ( i = 0; i < len; i ++ ) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertion_sort(ELEMTYPE * arr, int len)
{
	int i = 0, j = 0;
	ELEMTYPE tmp = 0;
	int pos = 0;
	for ( i = 1; i < len; i ++ ) {
		tmp = arr[i];
		pos = i;
		for ( j = i - 1; j >= 0 && arr[j] > tmp; j -- ) {
			arr[j + 1] = arr[j];
			pos = j;
		}
		arr[pos] = tmp;
	}
	return;
}

void shell_sort(ELEMTYPE * arr, int len)
{
	int N = len;
	int i = 0, j = 0, k = 0, tmp = 0, pos = 0;
	for ( N /= 2; N > 0; N /= 2 ) {
		for  ( k = N; k < 2*N; k ++ ) {
			//insertion sort
			for ( j = k; j < len; j += N ) {
				tmp = arr[j];
				pos = j;
				for ( i = j - N; i >= 0 && arr[i] > tmp; i -= N ) {
					arr[i + N] = arr[i];
					pos = i;
				}
				arr[pos] = tmp;
			}
		}
		print_array(arr, len);
	}
	
	return;
}

//build heap, max in top
void build_heap(ELEMTYPE * arr, int len, int start)
{
	int i = 0, tmp = 0, big_one = 0;
	if ( 2 * start + 1 > len ) {
		return;
	}
	for ( i = start; i > 0; i -- ) {
		if ( 2 * i + 1 > len ) { //just one left child
			if ( arr[i] < arr[2 * i] ) {
				swap_in_heap(arr, i, 2 * i);
				build_heap(arr, len, 2 * i);
			}
		} else { //two children
			big_one = max_in_heap(arr, 2 * i, 2 * i + 1);
			if ( arr[i] < arr[big_one] ) {
				swap_in_heap(arr, i, big_one);
				build_heap(arr, len, big_one);
			}
		}
	}
}

void heap_sort(ELEMTYPE * arr, int len)
{
	build_heap(arr, len, ( len - 1 ) / 2);
	delete_max(arr, len);
}

void swap_in_heap(ELEMTYPE * arr, int a, int b)
{
	ELEMTYPE tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
	return;
}

int max_in_heap(ELEMTYPE * arr, int a, int b)
{
	return arr[a] > arr[b] ? a : b;
}

void print_heap(ELEMTYPE * arr, int len)
{
	int i = 0;
	int current = 0, level = 0;
	for (i = 1; i < len; i ++ ) {
		printf("%d ", arr[i]);
		current ++;
		if ( current == pow(2, level) ) {
			current = 0;
			level ++;
			printf("\n");
		}
	}
	printf("\n");
	return;
}

void delete_max(ELEMTYPE * arr, int len)
{
	int tmp = 0, i = 0, max_pos = 0, heap_len = len - 1;
	while ( heap_len > 0 ) {
		tmp = arr[1];
		for ( i = 1; 2 * i <= heap_len;  ) {
			if ( 2 * i + 1 > heap_len ) {
				arr[i] = arr[2 * i];
				i = 2 * i;
			} else {
				max_pos = max_in_heap(arr, 2 * i, 2 * i + 1);
				arr[i] = arr[max_pos];
				i = max_pos;
			}
		}
		
		for ( ; i + 1 < len; i ++ ) {
			arr[i] = arr[i + 1];
		}
		
		arr[i] = tmp;
		heap_len --;
	}
	return;
}

void merge_sort(ELEMTYPE * arr, int len)
{
	ELEMTYPE tmp[len];
	arr = merge_array(arr, 0, len/2, len - 1, tmp);
	return;
}

ELEMTYPE * merge_array(ELEMTYPE * arr, int first, int mid, int last, ELEMTYPE * tmp){
	
	
	return tmp;
}