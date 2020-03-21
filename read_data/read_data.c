/********************************************************

read data

Author: Muhammed El-Yamani
muhammedelyamani92@gmail.com
January 2020


********************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef char *string;

/********************************************************
Functions Definitions
********************************************************/

/********************************************************
read Data from stored file Definition
********************************************************/

int *readData(string file_name, int *n)
{
  FILE *in_file = fopen(file_name, "r"); // read only

  // test for files not existing.
  if (in_file == NULL)
  {
    printf("Error! Could not open file\n");
    exit(-1);
  }

  // read the number of data from first index of file

  fscanf(in_file, "%d", n);
  int *arr = (int *)malloc(*n * sizeof(int));

  for (int i = 0; i < *n; i++)
  {
    // attempt to read the next line and store
    fscanf(in_file, "%d", &arr[i]);
  }

  fclose(in_file);

  return arr;
}
