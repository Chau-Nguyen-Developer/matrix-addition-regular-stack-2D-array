## Understand and Compare Different Methods of Implementing Matrices in C++ and Java
#### Overall
* Implement 4 versions of a matrix program and write a driver to test 3 different operations with matrices.
* The matrix operations that you should include are Addition, Subtraction and Multiplication.
#### User interface
* The driver can be as simple as **asking the user to enter two matrices** and then **presenting a simple menu** (will implement soon) that allows the user to select the operation they want to test.
* Have the menu in a loop so that the user can test any other operation unless they choose to exit the menu. 
* Also, provide the user an option to select two new matrices. Make sure that the result of every operation is printed out after the operation is chosen.
#### More information about matrices 
* The matrices should hold float values, so please use float data types in all versions.
* Also, make sure that you **do the check based on sizes** of the matrices if the chosen operation is permissible on the two matrices entered by the user.
* **The matrices can be entered by the user**by first entering the size of each matrix followed by the element. **Alternatively**, you can also provide the user the option of **reading both matrices from a simple text file,** where the first line is the size of the matrix and then followed by the elements of the matrix.
#### The four versions are as follows:  
* C/C++ version that uses a **regular stack dynamic 2D array** for representing the matrices. Limit the size of array to 100x100. Add appropriate functions to do the operations of addition, subtraction and multiplication of two matrices.
* C/C++ version that uses **a pointer to a pointer**(****p)** that is allocated memory using new or malloc to create the 2D matrices. Provide 3 functions, one for addition, subtraction and multiplication respectively, that take in the two matrices and return the result back (as a new matrix which is also declared as a pointer to a pointer)
* C/C++ version that **uses a pointer to a pointer as a private data in a class** called matrix (create this class) and add _overloaded operator functions_ (+ for addition, - for subtraction and * for multiplication) to the class for doing the matrix operations. _Add other appropriate member functions_, like constructors, destructors and any other helper functions.
* **Create a Java Class called matrix** and uses arrays and add appropriate methods for the matrix operations.
#### More instructions  
* Also test the multiplication function of each version by multiplying the same two matrices (say of size 10x10) and comment on the time taken to do the multiplication.
* For the last three versions, what happens to the time taken for multiplication as you start increasing the size of the matrices that you are multiplying. You can populate the matrices by random numbers.
* Upload your code (please make sure their are 4 separate source codes for each version, along with a report(.PDF format) that talks about the comparison between the 4 versions as well as the timing of using the last 3 version. (so, 5 items uploaded)
* Comment on any other aspects of comparison of these 4 versions. Please include screenshots of output of each version for any test set of matrices.
* Comment on the time taken by version 2,3 and 4 to complete the multiplication operation as the size of matrices increases. Show a table and a graph of time taken to complete as a function of matrix size (using square matrices for this comparison should be fine).
