/*
 * some basic sort algorithms.
 */

#include <stdio.h>

#define UNIT_TEST

void print_array(int array[], int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void insertion_sort(int array[], int len)
{
	int i, j, key;

	for(j = 1; j < len; j++)
	{
		key = array[j];
		i = j - 1;
		while (i >= 0 && array[i] > key)
		{
			array[i+1] = array[i]; 
			i--;
		}
		array[i+1] = key;
	}
}

#ifdef UNIT_TEST
int main(void)
{
	int array[] = {10, 8, 6, 4, 2, 1, 3, 5, 7, 9};

	print_array(array, 10);
	insertion_sort(array, 10);
	print_array(array, 10);

	return 1;
}
#endif
