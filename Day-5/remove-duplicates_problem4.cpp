#include<iostream>
using namespace std;
//a function to remove the duplicates in an array
void no_duplicate(int array_size, int array[]) {
    for (int counter = 0; counter < array_size; counter++) { 
        for (int counter1 = counter + 1; counter1 < array_size; ) {
            if (array[counter] == array[counter1]) {
                for (int counter2 = counter1; counter2 < array_size - 1; counter2++) {
                    array[counter2] = array[counter2 + 1];
                }
                array_size--; // Reduce size after removing duplicate
            } else {
                counter1++;
            }
        }
    }

    // Printing the array after removing duplicates
    cout << "Array after removing duplicates: ";
    for (int counter = 0; counter < array_size; counter++) {
        cout << array[counter] << " ";
    }
    cout << endl;
}

int main() {
    int array_size, array[100];
    cout << "Enter the size of the array: ";
    cin >> array_size;
    cout << "Enter the elements of the array: ";
    for (int counter = 0; counter < array_size; counter++) {
        cin >> array[counter];
    }
    no_duplicate(array_size, array);
}
