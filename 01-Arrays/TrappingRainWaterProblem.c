#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	return a > b ? a: b;
}

int min(int a, int b)
{
	return a < b ? a: b;
}

int findWater(int *arr, int size)
{
	int index, left[size], right[size], water = 0;
	left[0] = arr[0];
	for(index = 1; index < size; index++)
		left[index] = max(left[index-1], arr[index]);
	right[size-1] = arr[size-1];
	for(index = size-2; index >= 0; index--)
		right[index] = max(right[index+1], arr[index]);
	for(index = 0; index < size; index++)
		water += min(left[index], right[index]) - arr[index];
	return water;
}

int main()
{
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Maximum water can accumulate is = %d", findWater(arr, size));
}