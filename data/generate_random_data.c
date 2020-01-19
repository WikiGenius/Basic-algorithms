/********************************************************

generate random  data

Author: Muhammed El-Yamani
muhammedelyamani92@gmail.com
January 2020


********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef char* string;

void generateRandomArr(string, int);

int main(int argc, char const *argv[])
{
	// by default
	int n = 100;
	string file_name = "data.txt" ; 

	if (argc == 2)
	{
		n = atoi(argv[1]);
	}
	
	printf("printing to the file ...\n");

	generateRandomArr(file_name, n);

	printf("Done.\n");
	
	return 0;
}

void generateRandomArr(string file_name,  int n) 
{
	int *arr =  (int*)malloc(n * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < n; i++) 
	{
		arr[i] = (rand() % n) * (pow(-1, rand() % 2));
	}

    FILE *out_file = fopen(file_name, "w"); // write only 
           
    // test for files not existing. 
    if (out_file == NULL) 
    {       
    	printf("Error! Could not open file\n");             
    	exit(-1);  
    }
    //store number of data in first index in the file 
    fprintf(out_file, "%d ", n);
    // write to file 
    for (int i = 0; i < n;i++)
    {
        fprintf(out_file, "%d ", arr[i]); 
    } 
           
    free(arr);
    fclose(out_file);
}