  **This is all the comments/ helper functions that I removed from my main function.**   
  
   //Create a matrix to hold the result  
    double addMatrixResult[numRowsMatrix1][numColumnsMatrix1];
    
    ?

    
    
    // //HELPER FUNCTION: ADD TWO MATRICES
    // //double[][] addTwoMatrix(const *double[][], const* double[][])
    // bool addTwoMatrix(int rowMatrix1, int columnMatrix1, int rowMatrix2, int columnMatrix2, double firstMatrix[rowMatrix1][columnMatrix1], double secondMatrix[rowMatrix2][columnMatrix2], double result[rowMatrix1][columnMatrix1])
    // {
    //     if((rowMatrix1 != rowMatrix2) || (columnMatrix1 !=  columnMatrix2))
        
    //     {
    //         puts("Two matrices do not have same dimension. Cannot perform adding two matrices.");
    //         return false;
    //     }
    //     else
    //     {
    //         for(int i = 0; i < rowMatrix1; ++i)
    //         {
    //             for (int j = 0; j < columnMatrix1; ++j)
    //             {
    //                 result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
    // //             }
    //         }
    //         puts("Adding two matrices are complete succesfully.")
    //     }
    //     return true;
        
    // }

    // //HELPER FUNCTION: PRINT OUT ANY MATRIX. CAN BE USED IN TESTING AND IN PRINTING BACK RESULTS.
    // void printMatrix(int rows, int columns, double givenMatrix[rows][columns])
    // {
    //     for(int i = 0; i < rows; ++i)
    //     {
    //         for (int j = 0; j < columns; ++j)
    //         {
    //             printf("%lf ", givenMatrix[i][j]);
    //         }
    //     }
    // }

    // //HELPER FUNCTION: RECEIVE AND READ IN INPUT FROM USERS TO CREATE ANY MATRIX
    // void fillMatrix(int rows, int columns, double myMatrix[rows][columns])
    // {
    //     for (int i = 0; i < rows; ++i)
    //     {
    //         printf("Row %d: ", i + 1);
    //         for (int j = 0; j < columns; ++j)
    //         {
    //             scanf("%lf", &myMatrix[i][j]);
    //         }
    //     }
    //     printf("\n"); //Go to the next line for whatever next action
    // }