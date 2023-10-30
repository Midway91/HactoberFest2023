#include <iostream>
using namespace std;

/*
In this code I shall be practicing matrix multiplication
Matrix Multiplication code can be used for multiplying matrices af all orders
However, the order of the matrices being multiplied must order some rules
*/


int main()
{
    /*
    Defining rows and columns for first matrix
    */
    int rows_matrix_1;
    int columns_matrix_1;

    /*
    Defining rows and columns of the second matrix
    */
    int rows_matrix_2;
    int columns_matrix_2;

    /*
    Next we shall take user input for the number of rows and columns for both the matrices
    */

    cout<<"Enter Number of rows in matrix 1: ";
    cin>>rows_matrix_1;

    cout<<"Enter Number of columns in matrix 1: ";
    cin>>columns_matrix_1;

    cout<<"Enter Number of rows in matrix 2: ";
    cin>>rows_matrix_2;

    cout<<"Enter Number of columns in matrix 2: ";
    cin>>columns_matrix_2;

    /*
    For matrix multiplication, number of columns in the first matrix should equal number of
    rows in the second matrix. If not so, we shall display a message to inform the user that
    matrix multiplication is not possible in this case.
    */

    if (columns_matrix_1!=rows_matrix_2){
        cout<<"The Matrix Multiplication is not possible"<<endl;
        cout<<"Number of columns in first matrix must equal number of rows in second matrix";
        return 0;
    } 
    
    /*
    Next we shall take inpput from the user for the elements in the matrix
	*/
	
	// Entries for first matrix
	int matrix_1[rows_matrix_1][columns_matrix_1];
	
	for (int i=0; i<rows_matrix_1; i++){
		for (int j=0; j<columns_matrix_1; j++){
			cout<<"Enter Element Matrix 1["<<i<<"]["<<j<<"]: ";
			cin>>matrix_1[i][j];
		}
	}

    // Entries for second matrix
	int matrix_2[rows_matrix_2][columns_matrix_2];
	
	for (int i=0; i<rows_matrix_2; i++){
		for (int j=0; j<columns_matrix_2; j++){
			cout<<"Enter Element Matrix 2["<<i<<"]["<<j<<"]: ";
			cin>>matrix_2[i][j];
		}
	}

    cout<<"The First Matrix You created:\n";
    for (int i=0; i<rows_matrix_1; i++){
		for (int j=0; j<columns_matrix_1; j++){
			cout<<matrix_1[i][j]<<" ";
		}
        cout<<endl;
	}

    cout<<"The Second Matrix You created:\n";
    for (int i=0; i<rows_matrix_2; i++){
		for (int j=0; j<columns_matrix_2; j++){
			cout<<matrix_2[i][j]<<" ";
		}
        cout<<endl;
	}

    /*
    Now we are going to start our multiplication
    The code consists of 3 for loops
    So its time complexity is roughly O(n^3)
    To be more precise if m is the number of rows in first matrix is m, number of columns in second
    matrix is n and number of rows in second matrix is p, then the time complexity would be O(m*n*p)
    */

    /*Defining the final matrix that will come out as product*/
    int product_matrix[rows_matrix_1][columns_matrix_2];

    /*
    First we are going to iterate over the number of rows in matrix 1 as it is
    the number of rows in our final matrix then we iterate over the number of columns in the
    second matrix, which is also going to be the number of ccolumns in product matrix. At the
    end we iterate over the number of rows in second matrix which is the same as number of 
    columns in the first matrix. When multiplying the column number of element in matrix 1 should be
    the same as the rows number of element in the matrix 2. The row number of matrix 1 and column number of
    matrix 2 during multiplication is what determines the position of the resultant number in the
    product matrix.

    */

    cout<<"Your Product Matrix is\n";
    for (int i=0; i<rows_matrix_1; i++){
        for (int j=0; j<columns_matrix_2; j++){
            product_matrix[i][j] = 0;
            for (int k=0; k<rows_matrix_2; k++){
                product_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }

    /*Printing out our final result*/
    for (int i=0; i<rows_matrix_1; i++){
        for (int j=0; j<columns_matrix_2; j++){
            cout<<product_matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}
