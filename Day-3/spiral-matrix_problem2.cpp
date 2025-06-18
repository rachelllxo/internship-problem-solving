#include<iostream>
using namespace std;

int main() {
    int rows, columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    int matrix[100][100], spiral[10000], index = 0;

    // Input matrix
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> matrix[i][j];

 
    int top = 0, bottom = rows - 1, left = 0, right = columns - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            spiral[index++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            spiral[index++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                spiral[index++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                spiral[index++] = matrix[i][left];
            left++;
        }
    }

    int last = spiral[index - 1];
    for (int i = index - 1; i > 0; i--) {
        spiral[i] = spiral[i - 1];
    }
    spiral[0] = last;

    top = 0, bottom = rows - 1, left = 0, right = columns - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            matrix[top][i] = spiral[k++];
        top++;

        for (int i = top; i <= bottom; i++)
            matrix[i][right] = spiral[k++];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                matrix[bottom][i] = spiral[k++];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = spiral[k++];
            left++;
        }
    }

// printing the matrix
    cout << "\nSpiral Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
