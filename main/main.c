/********************************************************

main file

Author: Muhammed El-Yamani
muhammedelyamani92@gmail.com
January 2020


********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"algorithm.h"

void Sort(int*, const int, const int, const int , void(*type_sort)(int* , const int , const int , const int )); 


int main(int argc, char const *argv[])
{
	int q = 0;
	char *file_name = "data/data.txt";
	if (argc == 2)
	{
		q = atoi(argv[1]);

	}

	clock_t start, end;
	
	int n = 0;
	int* arr = readData(file_name,&n);

	printf("sorted array\n");
	start = clock();
	
	Sort(arr, n, 0, n - 1, quickSort);

	

	end = clock();

	for (int i = 0; i < n; i++) 
	{
	printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
	}
	double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // in seconds 
	printf("Sort(arr, n): took %f seconds to execute \n", time_taken);

	int index = bin_search(arr,n,q);	 
	printf("index  for query = %d : %d \n",q, index );
	return 0;
}

void Sort(int *arr, const int n, const int p, const int r,\
	void(*type_sort)(int* , const int , const int , const int )) 
{
    /********************************************************
    Sort functions:

    quickSort 
    mergeSort
    selectionSort
    insertionSort
    bubbleSort

    ********************************************************/
	type_sort(arr , n , p , r);
}
