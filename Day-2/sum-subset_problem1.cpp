#include <iostream>
using namespace std;

int main() {
    // Getting inputs 
    int array_size;
    cout << "Enter the size of the array: ";
    cin >> array_size;

    int array[100]; // Static array
    cout << "Enter the elements: ";
    for (int i = 0; i < array_size; i++) {
        cin >> array[i];
    }

    int target_value;
    cout << "Enter the target value: ";
    cin >> target_value;

    bool found = false; // To check if any subsets are found

    for (int start_counter = 0; start_counter < array_size; start_counter++) {
        for (int end_counter = start_counter + 1; end_counter < array_size; end_counter++) { //adds the first and the second index and so on..
            if (array[start_counter] + array[end_counter] == target_value) {
                cout << "The indexes are: ["<<start_counter <<"," << end_counter<<"]"<< endl;
                found = true;
            }
        }
    }

    if (!found) { // if subsets are not found 
        cout << "No subsets of the target value found." << endl;
    }

    return 0;
}
