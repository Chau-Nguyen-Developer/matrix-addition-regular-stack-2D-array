/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



//Question: is there any way that I can help to make the column number NOT global?
//Create an object and store in it?


int main()
{
    //FUNCTION PROTOTYPES
    bool addTwoMatrix(int rowMatrix1, int columnMatrix1, int rowMatrix2, int columnMatrix2,
                  double firstMatrix[rowMatrix1][columnMatrix1], 
                  double secondMatrix[rowMatrix2][columnMatrix2], 
                  double result[rowMatrix1][columnMatrix1]);
                  
    void printMatrix(int rows, int columns, double givenMatrix[rows][columns]);
    void fillMatrix(int rows, int columns, double myMatrix[rows][columns]);


    //CREATING FIRST MATRIX
    //Read in row numbers for first matrix.
    int numRowsMatrix1;
    printf("Enter the row numbers of first column: ");
    scanf("%d", &numRowsMatrix1);
    printf("You enter: %d\n", numRowsMatrix1);

    // Read in column numbers for first matrix.
    int numColumnsMatrix1;
    printf("Enter the column numbers of first column: ");
    scanf("%d", &numColumnsMatrix1);
    printf("You enter: %d\n", numColumnsMatrix1);
    
    //Create first matrix
    double firstMatrix[numRowsMatrix1][numColumnsMatrix1];
    
    //Read in first matrix
    fillMatrix(numRowsMatrix1,numColumnsMatrix1,firstMatrix);
    // for (int i = 0; i < numRowsMatrix1; ++i)
    // {
    //     printf("Row %d: ", i + 1);
    //     for(int k = 0; k < numColumnsMatrix1; ++k)
    //     {
    //         scanf("%lf", &firstMatrix[i][k]);
    //     }
    // }
    
    //Print matrix again to check 
    // puts("Print out first matrix to check.");
    // for (int i = 0; i < numRowsMatrix1; ++i)
    // {
    //     for(int k = 0; k < numColumnsMatrix1; ++k)
    //     {
    //         printf("%lf ", firstMatrix[i][k]);
    //     }
    //     printf("\n");
    // }

    printMatrix(numRowsMatrix1, numColumnsMatrix1,firstMatrix);
    
    //CREATING SECOND MATRIX
    //Read in row numbers for second matrix.
    int numRowsMatrix2;
    printf("Enter the row numbers of second column: ");
    scanf("%d", &numRowsMatrix2);
    printf("You enter: %d\n", numRowsMatrix2);

    // Read in column numbers for second matrix.
    int numColumnsMatrix2;
    printf("Enter the column numbers of first column: ");
    scanf("%d", &numColumnsMatrix2);
    printf("You enter: %d\n", numColumnsMatrix2);
    
    //Create second matrix
    double secondMatrix[numRowsMatrix2][numColumnsMatrix2];
    
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
    
    //Create a matrix to hold the result
    double addMatrixResult[numRowsMatrix1][numColumnsMatrix1];
    
    //Call the add two matrix function to fill in the "result" matrix
    // addTwoMatrix(int,         int,                   int,               int ,       double firstMatrix[][numColumnsMatrix1], double secondMatrix[][numColumnsMatrix1], double result[][numColumnsMatrix1]);
    addTwoMatrix(numRowsMatrix1, numColumnsMatrix1, numRowsMatrix2, numColumnsMatrix2, firstMatrix[][numColumnsMatrix1], secondMatrix[][numColumnsMatrix1], addMatrixResult[][numColumnsMatrix1]);
    printMatrix(numRowsMatrix1, numColumnsMatrix1, addMatrixResult[][numColumnsMatrix1]);
    
}


//HELPER FUNCTION: ADD TWO MATRICES
//double[][] addTwoMatrix(const *double[][], const* double[][])
bool addTwoMatrix(int rowMatrix1, int columnMatrix1, int rowMatrix2, int columnMatrix2, double firstMatrix[rowMatrix1][columnMatrix1], double secondMatrix[rowMatrix2][columnMatrix2], double result[rowMatrix1][columnMatrix1])
{
    if((rowMatrix1 != rowMatrix2) || (columnMatrix1 !=  columnMatrix2))
    
    {
        puts("Two matrices do not have same dimension. Cannot perform adding two matrices.");
        return false;
    }
    else
    {
        for(int i = 0; i < rowMatrix1; ++i)
        {
            for (int j = 0; j < columnMatrix1; ++j)
            {
                result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
            }
        }
        puts("Adding two matrices are complete succesfully.");
    }
    return true;
    
}

//HELPER FUNCTION: PRINT OUT ANY MATRIX. CAN BE USED IN TESTING AND IN PRINTING BACK RESULTS.
void printMatrix(int rows, int columns, double givenMatrix[rows][columns])
{
    for(int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            printf("%lf ", givenMatrix[i][j]);
        }
    }
}

//HELPER FUNCTION: RECEIVE AND READ IN INPUT FROM USERS TO CREATE ANY MATRIX
void fillMatrix(int rows, int columns, double myMatrix[rows][columns])
{
    for (int i = 0; i < rows; ++i)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < columns; ++j)
        {
            scanf("%lf", &myMatrix[i][j]);
        }
    }
    printf("\n"); //Go to the next line for whatever next action
}