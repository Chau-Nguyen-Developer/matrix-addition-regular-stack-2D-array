//PROGRAMMER: NGOC CHAU NGUYEN
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
    
    //MATRIX 1
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

    //Read in matrix 1
    for(int i = 0; i < rowsMatrix1; ++i)
    {
        for(int j = 0; j < columnsMatrix1; ++j)
        {
            fscanf(myFile, "%d", &matrix1[i][j]);
        }
    }

    //MATRIX 2
    int rowsMatrix2, columnsMatrix2;
    fscanf(myFile, "%d %d", &rowsMatrix2, &columnsMatrix2);
    //Allocate memory row of pointers for matrix 2
    int **matrix2 = (double *)malloc(rowsMatrix2 * sizeof(double *));
    //Allocate memory for each row
    for (int i = 0; i < rowsMatrix2; ++i)
    {
        matrix2[i] = (double *)malloc(columnsMatrix2 * sizeof(double));
    }

    //NEED TO PRINT OUT MATRIX TO CHECK

    //Close the file
    fclose(myFile);
    return 0;

}