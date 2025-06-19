#include<iostream>
using namespace std;

int main() {
    int matrix_size;
    int matrix_elements[100][100];

    // Getting input
    cout << "Enter the size of the matrix (n x n): ";
    cin >> matrix_size;

    cout << "Enter the elements in the matrix:\n";
    for (int row = 0; row < matrix_size; row++) {
        for (int col = 0; col < matrix_size; col++) {
            cin >> matrix_elements[row][col];
        }
    }

    // Transposing the matrix in-place
    for (int row = 0; row < matrix_size; row++) {
        for (int col = row + 1; col < matrix_size; col++) {
            int temp = matrix_elements[row][col];
            matrix_elements[row][col] = matrix_elements[col][row];
            matrix_elements[col][row] = temp;
        }
    }

    // Reversing each row in-place
    for (int row = 0; row < matrix_size; row++) {
        for (int col = 0; col < matrix_size / 2; col++) {
            int temp = matrix_elements[row][col];
            matrix_elements[row][col] = matrix_elements[row][matrix_size - 1 - col];
            matrix_elements[row][matrix_size - 1 - col] = temp;
        }
    }

    // Printing the rotated matrix
    cout << "The rotated matrix:\n";
    for (int row = 0; row < matrix_size; row++) {
        for (int col = 0; col < matrix_size; col++) {
            cout << matrix_elements[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
