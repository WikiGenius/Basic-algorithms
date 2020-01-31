/********************************************************

Different types of sort 

Author: Muhammed El-Yamani
muhammedelyamani92@gmail.com
January 2020


********************************************************/
#ifndef SORT_H
#define SORT_H

/********************************************************
Functions Declaration
********************************************************/


/********************************************************
Common Declaration
********************************************************/

void swap(int* a, int *b);


/********************************************************
Bubble Sort Declaration
********************************************************/

void Switch(int*arr, int n, int* not_sorted);
void bubbleSort(int* arr, const int n, const int p, const int r);


/********************************************************
Selection Sort Declaration
********************************************************/

int IndexOfMinimum(int* arr, int n, int start_index);
void selectionSort(int* arr, const int n, const int p, const int r);

/********************************************************
Insertion Sort Declaration
********************************************************/

void insert(int*arr, int n, int rightIndex);
void insertionSort(int* arr, const int n, const int p, const int r);
/********************************************************
Merge Sort Declaration
********************************************************/

void merge(int* arr, const int n, const int p, const int q, const int r);
void mergeSort(int* arr, const int n, const int p, const int r);

/********************************************************
Quick Sort Declaration
********************************************************/

int divide(int * arr, int p, int r);
void quickSort(int* arr, const int n, const int p, const int r);

/********************************************************
General Sort Declaration
********************************************************/

void Sort(int*, const int, const int, const int , void(*type_sort)(int* , const int , const int , const int )); 

#endif // !SORT_H

