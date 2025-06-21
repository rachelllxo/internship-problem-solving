#include<iostream>
using namespace std;

//first, we sort the array in ascending order [small to large number]
void sort(int array_size, int array_elements[]){
	for(int outer_loop=0;outer_loop<array_size;outer_loop++){ //traverses from the first 
		for(int inner_loop=outer_loop+1;inner_loop<array_size;inner_loop++){ //traverses from the second element (1 step forward)
			if (array_elements[outer_loop]>array_elements[inner_loop]){
				int sorted_array=array_elements[outer_loop]; 
				array_elements[outer_loop]=array_elements[inner_loop]; 
				array_elements[inner_loop]=sorted_array;
			}
		}
	}
}

//finds the largest common element from both arrays
void CommonElement(int array_size1, int array_size2, int array1[100], int array2[100]){
	sort(array_size1, array1); // sort array1
	sort(array_size2, array2); // sort array2

	int largest_common = -1; //to mean no common element is found 

	for (int counter1 = 0; counter1 < array_size1; counter1++){
		for (int counter2 = 0; counter2 < array_size2; counter2++){
			if (array1[counter1] == array2[counter2]){
				if (array1[counter1] > largest_common){
					largest_common = array1[counter1];
				}
				break; // avoid matching duplicates in array2
			}
		}
	}

	if (largest_common != -1){
		cout << "Largest common element is: " << largest_common;
	}
	else{
		cout << "No common elements found.";
	}
}

int main(){
	//getting inputs 
	int array_size1, array_size2, array1[100], array2[100];
	cout << "Enter the size of array 1: ";
	cin >> array_size1;
	cout << "Enter the elements of the array 1: ";
	for (int count = 0; count < array_size1; count++){
		cin >> array1[count];
	}

	cout << "Enter the size of array 2: ";
	cin >> array_size2;
	cout << "Enter the elements of array 2: ";
	for (int count = 0; count < array_size2; count++){
		cin >> array2[count];
	}

	CommonElement(array_size1, array_size2, array1, array2);
}
