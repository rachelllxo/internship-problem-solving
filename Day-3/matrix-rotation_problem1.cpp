#include<iostream>
using namespace std;

int main() {
    int arr[100][100], matrix_size;
     //getting inputs 
    cout << "Enter the size of the matrix: ";
    cin >> matrix_size;
	int matrix_elements[100][100]; 

    cout << "Enter the elements in the matrix:\n";
    for (int rows = 0; rows < matrix_size; rows++) {
        for (int columns = 0; columns < matrix_size; columns++) {
            cin >> matrix_elements[rows][columns];
        }
    }

    // Transposing the matrix
    for (int rows = 0; rows < matrix_size; rows++) {
        for (int columns = rows + 1; columns < matrix_size; columns++) {
            int transpose_matrix = matrix_elements[rows][columns];
            matrix_elements[rows][columns] = matrix_elements[columns][rows];
            matrix_elements[columns][rows] = transpose_matrix;
        }
    }

    // Reversing each row
    for (int rows = 0; rows < matrix_size; rows++) {
        for (int columns = 0; columns < matrix_size / 2; columns++) {
            int rotated_matrix = matrix_elements[rows][columns];
            matrix_elements[rows][columns] = matrix_elements[rows][matrix_size - 1 - columns];
            matrix_elements[rows][matrix_size - 1 - columns] = rotated_matrix;
        }
    }

    // Printing the rotated matrix
    cout << "The rotated matrix:\n";
    for (int rows = 0; rows < matrix_size; rows++) {
        for (int columns = 0; columns < matrix_size; columns++) {
            cout << matrix_elements[rows][columns] << " ";
        }
        cout << endl;
    }

    return 0;
};