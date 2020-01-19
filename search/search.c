/********************************************************

Different types of search

Author: Muhammed El-Yamani
muhammedelyamani92@gmail.com
January 2020


********************************************************/

#include"search.h"

/********************************************************
Functions Definition
********************************************************/

/********************************************************
Binary search Definition
********************************************************/

int bin_search (int *arr, int n, int query)
{
	int p = 0;
	int r = n - 1;
	int q;

	label:

	q = (p + r) / 2;

	if (p > r)
	{
		return -1;
	}
	else if (query == arr[q])
	{
		return q;
	}
	else if (query < arr[q])
	{
		//go to left arr
		r = q - 1;
		goto label;
	}
	else if (query > arr[q])
	{
		//go to right arr
		p = q + 1;
		goto label;
	}

return -1;
}