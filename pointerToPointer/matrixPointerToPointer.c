#include <stdio.h>
#include <stdlib.h>

int main()
{
    char fileName[100];

    //Ask user for file name
    puts("Please enter the file name: ");
    scanf("%s", fileName); // read a string, maximum 99 characters with one null terminator

    //Open the file
    FILE *myFile = fopen(fileName, "r");
    if(myFile == NULL)
    {
        puts("Cannot opening file.");
        return -1;
    }
    
    puts("Successfully opened the file.");
    
    //Reading from the file to create matrix
    int rowsMatrix1, columnsMatrix1;
    fscanf(myFile, "%d %d", &rowsMatrix1, &columnsMatrix1);
    //Allocate matrix 1 (aka allocate the row of pointers (type double))
    double **matrix1 = (double*)malloc(rowsMatrix1 * sizeof(double *));
    //Allocate memory for each row
    for(int i = 0; i < rowsMatrix1; ++i)
    {
        matrix1[i] = (double *)malloc(columnsMatrix1 * sizeof(double));
        if (matrix1[i] == NULL)
        {
            printf("Memory allocation failed for row %d.\n", i);
            return -1;
        }
    }

    //Close the file
    fclose(myFile);
    return 0;

}