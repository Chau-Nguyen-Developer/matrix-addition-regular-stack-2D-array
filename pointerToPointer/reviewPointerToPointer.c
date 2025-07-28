#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 3, cols = 4;
    double **matrix;

    //Step 1: Allocate memory for the row pointers
    //Takes number of rows times the size of a double pointer
    matrix = (double **)malloc(rows * sizeof(double *));
    if(matrix == NULL)
    {
        printf("Memory allocation failed for row pointers.\n");
        return 1;
    }

    //Step 2: Allocate memory for each row
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = (double *)malloc(cols * sizeof(double));
        //Some explanation: malloc function allocates a block of memory and returns a void* pointer, 
        //which is a generic pointer.  
        //(double *) converts the void* pointer to a pointer of type double, so I can assign it to matrix[i],
        //which is of type double *
        //The cast is optional in C, but necessary in C++. 


        if (matrix[i] == NULL)
        {
            printf("Memory allocation failed for row %d.\n", i);
            return 1;
        }
    }

}