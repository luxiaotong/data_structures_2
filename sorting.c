#include "sorting.h"



void print_array(ElEMTYPE * arr, int len)
{
	int i = 0;
	for ( i = 0; i < len; i ++ ) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertion_sort(ElEMTYPE * arr, int len)
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
	return;
}

void shell_sort(ElEMTYPE * arr, int len)
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
