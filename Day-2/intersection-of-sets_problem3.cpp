#include <iostream>
using namespace std;

int main() {
    int size1, size2;
    int set1[100], set2[100], intersection[100];
    int intersect_size = 0;

    // Input for Set 1
    cout << "Enter number of elements in Set 1: "; 
    cin >> size1;
    cout << "Enter elements of Set 1:\n"; 
    for (int start_counter = 0; start_counter < size1; start_counter++) {
        cin >> set1[start_counter]; 
    }

    // Input for Set 2
    cout << "Enter number of elements in Set 2: ";
    cin >> size2; // 3
    cout << "Enter elements of Set 2:\n";
    for (int start_counter = 0; start_counter < size2; start_counter++) {
        cin >> set2[start_counter]; 
    }

    // Finding intersection using comparison
    for (int start_counter1 = 0; start_counter1 < size1; start_counter1++) { 
        for (int start_counter2 = 0; start_counter2 < size2; start_counter2++) {
            if (set1[start_counter1] == set2[start_counter2]) { 
                // Check if already in intersection array
                bool alreadyExists = false;
                for (int start_counter3 = 0; start_counter3 < intersect_size; start_counter3++) { 
                    if (intersection[start_counter3] == set1[start_counter1]) { 
                        alreadyExists = true;
                        break;
                    }
                }

                if (!alreadyExists) {
                    intersection[intersect_size] = set1[start_counter1];
                    intersect_size++;
                }
            }
        }
    }

    // Output result
    if (intersect_size == 0) {
        cout << "No intersection found.\n";
    } else {
        cout << "Intersection of the two sets: ";
        for (int start_counter = 0; start_counter < intersect_size; start_counter++) {
            cout << intersection[start_counter] << " ";
        }
        cout << endl;
    }

    return 0;
}
