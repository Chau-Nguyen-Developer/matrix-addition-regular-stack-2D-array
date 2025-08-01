//PROGRAMMER: NGOC CHAU NGUYEN
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    
    ////MATRIX 1
    //Reading from the file to create matrix
    int rowsMatrix1, columnsMatrix1;
    fscanf(myFile, "%d %d", &rowsMatrix1, &columnsMatrix1);

    //Print out rows and columns number for matrix 1
    //Allocate matrix 1 (aka allocate the row of pointers (type double))
    double **matrix1 = (double**)malloc(rowsMatrix1 * sizeof(double *));
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
    printf("Matrix 1. Rows: %d, Columns: %d\n", rowsMatrix1, columnsMatrix1);
    for(int i = 0; i < rowsMatrix1; ++i)
    {
        printf("Row %d\n", i);
        for(int j = 0; j < columnsMatrix1; ++j)
        {
            fscanf(myFile, "%lf", &matrix1[i][j]);
            printf("%lf ", matrix1[i][j]);
        }
        puts("\n");
    }
    ////MATRIX 2
    int rowsMatrix2, columnsMatrix2;
    fscanf(myFile, "%d %d", &rowsMatrix2, &columnsMatrix2);
    double **matrix2 = (double**)malloc(rowsMatrix2 * sizeof(double *));
    //Allocate memory for each row
    for(int i = 0; i < rowsMatrix2; ++i)
    {
        matrix2[i] = (double *)malloc(columnsMatrix2 * sizeof(double));
        if (matrix2[i] == NULL)
        {
            printf("Memory allocation failed for row %d.\n", i);
            return -1; // need to look into how to return error code. Use perror?
        }
    }
    printf("Matrix 2. Rows: %d. Columns: %d\n", rowsMatrix2, columnsMatrix2);

    puts("Read in matrix 2");
    for(int i = 0; i < rowsMatrix2; ++i)
    {
        printf("Row %d\n", i);
        for(int j = 0; j < columnsMatrix2; ++j)
        {
            fscanf(myFile, "%lf", &matrix2[i][j]);
            printf("%lf ", matrix2[i][j]);
        }
        puts("\n");
    }

    puts("Successfully read in the matrices from the file.");

    //MATRIX ADDITION
    puts("Matrix Addition");
    //Create a matrix to hold addition result
    bool canAdd, canSubtract, canMultiply;
    if((rowsMatrix1 == rowsMatrix2) && (columnsMatrix1 == columnsMatrix2))
    {
        canAdd = true;
        canSubtract = true;
    }
    if(canAdd)
    {
        double **addResult = (double**)malloc(rowsMatrix1 * sizeof(double *));
       //Allocate memory for each row
        for(int i = 0; i < rowsMatrix1; ++i)
        {
            addResult[i] = (double *)malloc(columnsMatrix1 * sizeof(double));
            if (addResult[i] == NULL)
            {
                printf("Memory allocation failed for row %d.\n", i);
                return -1;
            }
        }
        puts("Printing out result matrix addition.");
        for(int i = 0; i < rowsMatrix1; ++i)
        {
            printf("Row %d: ", i);
            for (int j = 0; j < columnsMatrix1; ++j)
            {
                addResult[i][j] = matrix1[i][j] + matrix2[i][j];
                printf("%lf ", addResult[i][j]);
            }
            puts("\n");
        }
    }
    else
    {
        puts("Cannot add two matrices.");
    }
    
    //MATRIX SUBTRACTION
    if(canSubtract)
    {
        double **subtractResult = (double**)malloc(rowsMatrix1 * sizeof(double *));
       //Allocate memory for each row
        for(int i = 0; i < rowsMatrix1; ++i)
        {
            subtractResult[i] = (double *)malloc(columnsMatrix1 * sizeof(double));
            if (subtractResult[i] == NULL)
            {
                printf("Memory allocation failed for row %d.\n", i);
                return -1;
            }
        }

        puts("Matrix Subtraction");
        puts("Printing out result matrix subtraction.");
        for(int i = 0; i < rowsMatrix1; ++i)
        {
            printf("Row %d: ", i);
            for (int j = 0; j < columnsMatrix1; ++j)
            {
                subtractResult[i][j] = matrix1[i][j] - matrix2[i][j];
                printf("%lf ", subtractResult[i][j]);
            }
            puts("\n");
        }
    }
    else
    {
        puts("Cannot subtract two matrices.");
    }
    //MATRIX MULTIPLICATION
    if(columnsMatrix1 == rowsMatrix2)
    {
        canMultiply = true;
        puts("Can multiply these two matrices.");
    }
    if(canMultiply)
    {
        double **multiplyResult = (double**)malloc(rowsMatrix1 * sizeof(double *));

        //Allocate memory for each row - matrix multiplication
        for(int i = 0; i < rowsMatrix1; ++i)
        {
            multiplyResult[i] = (double *)malloc(columnsMatrix2 * sizeof(double));
            if (multiplyResult[i] == NULL)
            {
                printf("Memory allocation failed for row %d.\n", i);
                return -1;
            }
        }

        puts("Printing out result matrix multiplication.");
      //Initialize my result matrix with 0 first, to make sure it does not have garbage values.
        for (int i = 0 ; i < rowsMatrix1; ++i)
        {
            for (int j = 0; j < columnsMatrix2; ++j)
            {
                multiplyResult[i][j] = 0;
            }
        }
        //Do matrix multiplication
        //numColumnsMatrix1 == numRowsMatrix2
        double temp = 0.0;

        //int b = matrix2Columns
        //int i = matrix1Rows
        //int j = matrix1Columns = matrix2Rows
        for(int b = 0; b < columnsMatrix2; ++b)
        {   printf("Row %d: ", b);
            for(int i = 0; i < rowsMatrix1; ++i)
            {
                for(int j = 0; j < columnsMatrix1; ++j)
                {
                    temp = temp + (matrix1[i][j] * matrix2[j][b]);
                }
                multiplyResult[i][b] = temp;
                printf("%lf ", multiplyResult[i][b]);
                temp = 0;
            }
            puts("\n");
        }
    }
    else
    {
        puts("Cannot do matrix multiplication. Incompatible matrix dimension.");
    }

    //Freeing my memory. 
    for (int i = 0; i < rowsMatrix1; ++i)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rowsMatrix2; ++i)
    {
        free(matrix2[i]);
    }
    free(matrix2);

    //Close the file
    fclose(myFile);
    return 0;

}