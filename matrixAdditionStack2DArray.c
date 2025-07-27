//PROGRAMMER: NGOC CHAU NGUYEN

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>





//Question: is there any way that I can help to make the column number NOT global?
//Create an object and store in it?


int main()
{
    bool canAdd = false;
    bool canSubtract = false;
    bool canMultiply = false;
    
    //CREATING FIRST MATRIX
    //Read in row numbers for first matrix.
    int numRowsMatrix1;
    printf("Enter the row numbers of first matrix: ");
    scanf("%d", &numRowsMatrix1);
    printf("You enter: %d\n", numRowsMatrix1);

    // Read in column numbers for first matrix.
    int numColumnsMatrix1;
    printf("Enter the column numbers of first matrix: ");
    scanf("%d", &numColumnsMatrix1);
    printf("You enter: %d\n", numColumnsMatrix1);
    
    //Create first matrix
    double firstMatrix[numRowsMatrix1][numColumnsMatrix1];
    
    //Read in first matrix
    for (int i = 0; i < numRowsMatrix1; ++i)
    {
        printf("Row %d: ", i + 1);
        for(int k = 0; k < numColumnsMatrix1; ++k)
        {
            scanf("%lf", &firstMatrix[i][k]);
        }
    }
    
    //Print matrix again to check 
    puts("Print out first matrix to check.");
    for (int i = 0; i < numRowsMatrix1; ++i)
    {
        for(int k = 0; k < numColumnsMatrix1; ++k)
        {
            printf("%lf ", firstMatrix[i][k]);
        }
        printf("\n");
    }
    
    //CREATING SECOND MATRIX
    //Read in row numbers for second matrix.
    int numRowsMatrix2;
    printf("Enter the row numbers of second matrix: ");
    scanf("%d", &numRowsMatrix2);
    printf("You enter: %d\n", numRowsMatrix2);

    // Read in column numbers for second matrix.
    int numColumnsMatrix2;
    printf("Enter the column numbers of second matrix: ");
    scanf("%d", &numColumnsMatrix2);
    printf("You enter: %d\n", numColumnsMatrix2);
    
    //Create second matrix
    double secondMatrix[numRowsMatrix2][numColumnsMatrix2];
    puts("Hit enter to go to the next row.");

    //Read in second matrix
    for (int i = 0; i < numRowsMatrix2; ++i)
    {
        printf("Row %d: ", i + 1);
        for(int k = 0; k < numColumnsMatrix2; ++k)
        {
            scanf("%lf", &secondMatrix[i][k]);
        }
    }
    
    //Print matrix again to check 
    puts("Print out second matrix to check.");
    for (int i = 0; i < numRowsMatrix2; ++i)
    {
        for(int k = 0; k < numColumnsMatrix2; ++k)
        {
            printf("%lf ", secondMatrix[i][k]);
        }
        printf("\n");
    }
    
    
    //Adding two matrices together
    puts("You are about adding two matrices together.");
    puts("Hit enter to go to the next row.");
    double resultAddition[numRowsMatrix1][numColumnsMatrix1];
    if((numRowsMatrix1 != numRowsMatrix2) && (numColumnsMatrix1 != numColumnsMatrix2))
    {
        
        puts("Two matrices have different dimension. Cannot do addition.");
    }
    else
    {
        canAdd = true;
        canSubtract = true;
        //Initialize my result matrix with 0 first, to make sure it does not have garbage values.
        for (int i = 0 ; i < numRowsMatrix1; ++i)
        {
            for (int j = 0; j < numColumnsMatrix1; ++j)
            {
                resultAddition[i][j] = 0;
            }
        }
        
        //Calculating the matrix
        for(int i = 0; i < numRowsMatrix1; ++i)
        {
            for(int j = 0; j < numColumnsMatrix1; ++j)
            {
                //result[i][j] = result[i][j] + (firstMatrix[i][j] * secondMatrix[i][j]);
                resultAddition[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
            }
        }
        puts("Matrix addition is success.");
    }
    
    puts("Print out result matrix to check.");
    for (int i = 0; i < numRowsMatrix1; ++i)
    {
        for(int k = 0; k < numColumnsMatrix1; ++k)
        {
            printf("%lf ", resultAddition[i][k]);
        }
        printf("\n");
    }

    //MATRIX SUBTRACTION
    if(canSubtract)
    {
        puts("Can do subtraction between these two matrices.");
        double matrixSubtraction[numRowsMatrix1][numColumnsMatrix1];
        //Subtracting the matrices
        for(int i = 0; i < numRowsMatrix1; ++i)
        {
            for(int j = 0; j < numColumnsMatrix1; ++j)
            {
                matrixSubtraction[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
            }
        }
        puts("Print out result matrix to check.");
        for (int i = 0; i < numRowsMatrix1; ++i)
        {
            for(int k = 0; k < numColumnsMatrix1; ++k)
            {
                printf("%lf ", matrixSubtraction[i][k]);
            }
            printf("\n");
        }

    }
    else
    {
        puts("Cannot do subtraction. Uncompatible dimensions.");
    }

    //MATRIX MULTIPLICATION
    if(numColumnsMatrix1 == numRowsMatrix2)
    {
        puts("Can do matrix multiplication");
        double matrixMultiplication[numRowsMatrix1][numColumnsMatrix2];

        //Initialize my result matrix with 0 first, to make sure it does not have garbage values.
        for (int i = 0 ; i < numRowsMatrix1; ++i)
        {
            for (int j = 0; j < numColumnsMatrix2; ++j)
            {
                matrixMultiplication[i][j] = 0;
            }
        }
        //Do matrix multiplication
        //numColumnsMatrix1 == numRowsMatrix2
        double temp = 0.0;

        //int b = matrix2Columns
        //int i = matrix1Rows
        //int j = matrix1Columns = matrix2Rows
        for(int b = 0; b < numColumnsMatrix2; ++b)
        {
            for(int i = 0; i < numRowsMatrix1; ++i)
            {
                for(int j = 0; j < numColumnsMatrix1; ++j)
                {
                    temp = temp + (firstMatrix[i][j] * secondMatrix[j][b]);
                }
                matrixMultiplication[i][b] = temp;
                temp = 0;
            }
        }

        puts("Print out result matrix to check.");
        for (int i = 0; i < numRowsMatrix1; ++i)
        {
            for(int k = 0; k < numColumnsMatrix2; ++k)
            {
                printf("%lf ", matrixMultiplication[i][k]);
            }
            printf("\n");
        }

    }
    else
    {
        puts("Cannot do matrix multiplication. Dimension of two matrices are uncompatible.");
    }
}
