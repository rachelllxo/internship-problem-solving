#include<iostream>
using namespace std;

int main() {
    // Getting input for array size
    int array_size;  
    cout << "Enter the size of the array: ";
    cin >> array_size;

    // Declaring the array
    int arr[array_size];  

    // Getting input for array elements
    cout << "Enter the elements of the array: ";
    for (int element_position = 0; element_position < array_size; element_position++) {
        cin >> arr[element_position];
    }

    // Getting the chunk size 'k' for reversing in segments
    int chunk_size;
    cout << "Enter a chunk size: ";
    cin >> chunk_size;

    // Reversing in chunks of size k
    for (int element_position = 0; element_position < array_size; element_position += chunk_size) {
        int start_index = element_position; 
        int end_index = element_position + chunk_size - 1;

        // Handling case when end goes beyond array
        if (end_index >= array_size) {
            end_index = array_size - 1;
        }

        // Swapping elements in the chunk
        while (start_index < end_index) {
            int temp = arr[start_index];
            arr[start_index] = arr[end_index];
            arr[end_index] = temp;
            start_index++;
            end_index--;
        }
    }

    // Output the reversed array
    cout << "Reversed array in chunks: ";
    for (int element_position = 0; element_position < array_size; element_position++) {
        cout << arr[element_position] << " ";
    }

    return 0;
}
