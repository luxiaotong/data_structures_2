#include "sorting.h"



ElEMTYPE * insertion_sort(ElEMTYPE * arr, int len)
{
	int i = 0, j = 0;
	ElEMTYPE tmp = 0;
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
	return arr;
}

void print_array(ElEMTYPE * arr, int len)
{
	int i = 0;
	for ( i = 0; i < len; i ++ ) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
