#include<iostream>
using namespace std;
// we first merge the two arrays 
void merge(int array1[100], int array2[100], int array_size, int merged_array[200]) {
	int index = 0;

	for (int counter1 = 0; counter1 < array_size; counter1++) {
		merged_array[index] = array1[counter1];
		index++;
	}

	for (int counter2 = 0; counter2 < array_size; counter2++) {
		merged_array[index] = array2[counter2];
		index++;
	}
}

void merge_sorted_array(int merged_array[200], int total_size) {
	// sorting the merged array
	for (int count3 = 0; count3 < total_size; count3++) {
		for (int count4 = count3 + 1; count4 < total_size; count4++) {
			if (merged_array[count3] > merged_array[count4]) {
				int sorted_array = merged_array[count3];
				merged_array[count3] = merged_array[count4];
				merged_array[count4] = sorted_array;
			}
		}
	}
}

int main() {
	int array_size, array1[100], array2[100], merged_array[200];

	cout << "Enter the size of the array: ";
	cin >> array_size;

	cout << "Enter the array 1 elements: ";
	for (int count = 0; count < array_size; count++) {
		cin >> array1[count];
	}

	cout << "Enter the array 2 elements: ";
	for (int count = 0; count < array_size; count++) {
		cin >> array2[count];
	}

	merge(array1, array2, array_size, merged_array);
	int total_size = array_size * 2; //creating an array that stores both the arrays and grouping the array to do sorting 

	merge_sorted_array(merged_array, total_size);

	cout << "Merge Sorted array: ";
	for (int i = 0; i < total_size; i++) {
		cout << merged_array[i] << " ";
	}
	cout << endl;

	
}
