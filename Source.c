#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<random>
#include"Sort.h"
void getRandomArr(int* arr, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 200 *(pow(-1, rand() % 2));
	}
}
void Sort(int* arr, const int n, const int p, const int r,\
	void(*type_sort)(int* , const int , const int , const int )) {
	type_sort(arr , n , p , r);
}
/********************************************************
Sort functions:

quickSort 
mergeSort
selectionSort
insertionSort
bubbleSort

********************************************************/

int main() {
	clock_t start, end;
	
	const int n = 100000;
	int arr[n];
	getRandomArr(arr, n);
	printf("random array\n");
	for (int i = 0; i < n; i++) {
		printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
	}
	printf("sorted array\n");
	start = clock();
	
	Sort(arr, n, 0, n - 1, selectionSort);
		 
		

	end = clock();

	for (int i = 0; i < n; i++) {
	printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
	}
	double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // in seconds 
	printf("Sort(arr, n): took %f seconds to execute \n", time_taken);
	system("PAUSE");
	return 0;
}
