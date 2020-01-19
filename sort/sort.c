/********************************************************

Different types of sort

Author: Muhammed El-Yamani
muhammedelyamani92@gmail.com
January 2020


********************************************************/

#include"sort.h"
#include<stdlib.h>

/********************************************************
Functions Definitions
********************************************************/

/********************************************************
Common Definition
********************************************************/

void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/********************************************************
Bubble Sort Definition
********************************************************/

void Switch(int *arr, int n, int *not_sorted) 
{
	*not_sorted = 0;
	for (int i = 0; i < n - 1; i++) 
	{
		if (arr[i + 1] < arr[i]) 
		{
			swap(&arr[i + 1], &arr[i]);
			*not_sorted = 1;
		}
	}
}
void bubbleSort(int *arr, const int n, const int p, const int r) 
{
	int not_sorted = 1;
	while (not_sorted) 
	{
		Switch(arr, n, &not_sorted);
	}
}

/********************************************************
Selection Sort Definition
********************************************************/

int IndexOfMinimum(int *arr, int n, int start_index) 
{
	int smallest_index = start_index;

	for (int i = start_index + 1; i < n; i++)
	{
		if (arr[i] < arr[smallest_index])
		{
			smallest_index = i;
		}
	}
	return smallest_index;
}
void selectionSort(int *arr, const int n, const int p, const int r) 
{
	for (int i = 0; i < n; i++) 
	{
		int min_index = IndexOfMinimum(arr, n, i);
		swap(&arr[i], &arr[min_index]);
	}
}

/********************************************************
Insertion Sort Definition
********************************************************/

void insert(int *arr, int n, int rightIndex) 
{
	int key = arr[rightIndex];
	int j = rightIndex - 1;
	for (; j >= 0 && key < arr[j]; j--) 
	{
		arr[j + 1] = arr[j];

	}
	arr[j + 1] = key;
}
void insertionSort(int *arr, const int n, const int p, const int r) 
{
	for (int i = 1; i < n; i++) 
	{
		insert(arr, n, i);
	}
}////////////////////////////////////////////////////////

/********************************************************
Merge Sort Definition
********************************************************/

void merge(int *arr, const int n, const int p, const int q, const int r) 
{
	const int nL = q - p + 1;
	const int nR = r - q;
	int *arrLeft = (int*)calloc(nL, sizeof(int));
	int *arrRight = (int*)calloc(nR, sizeof(int));

	for (int i = 0; i < nL; i++) 
	{
		arrLeft[i] = arr[p + i];
	}
	for (int i = 0; i < nR; i++) {
		arrRight[i] = arr[q + 1 + i];
	}
	int arrL_count = 0, arrR_count = 0, arr_count = p;
	//comparison
	for (; arrL_count < nL && arrR_count < nR; arr_count++) 
	{
		if (arrLeft[arrL_count] < arrRight[arrR_count]) 
		{
			arr[arr_count] = arrLeft[arrL_count];
			arrL_count++;
		}
		else 
		{
			arr[arr_count] = arrRight[arrR_count];
			arrR_count++;
		}
	}
	//if there are remind
	for (; arrL_count < nL; arrL_count++, arr_count++) 
	{
		arr[arr_count] = arrLeft[arrL_count];
	}
	for (; arrR_count < nR; arrR_count++, arr_count++) 
	{
		arr[arr_count] = arrRight[arrR_count];
	}
	free(arrLeft);
	free(arrRight);
}
void mergeSort(int *arr, const int n, const int p, const int r) 
{

	if (p < r) 
	{
		int q = (p + r) / 2;
		//recursion
		mergeSort(arr, n, p, q);
		mergeSort(arr, n, q + 1, r);
		merge(arr, n, p, q, r);
	}

}

/********************************************************
Quick Sort Definition
********************************************************/

int divide(int *arr, int p, int r) 
{

	int q = p;//small index
	int u = p;//unkown index
	int piv = p; //pivot // you can choose any random pivot
	
	for ( ; u <= r; u++) 
	{
		if (u == piv) 
		{
			q++; continue; 
		}
		if (arr[u] <= arr[piv]) 
		{
			swap(&arr[u], &arr[q]);
			q++;
		}
	}
	q--;
	swap(&arr[q], &arr[piv]);
	return q;
}
void quickSort(int *arr, const int n, const int p, const int r) 
{
	if (p < r) 
	{
		int q = divide(arr, p, r);
		//left pivot
		quickSort(arr, n, p, q - 1);
		//right pivot
		quickSort(arr, n, q + 1, r);
	}
}


