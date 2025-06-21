#include<iostream>
using namespace std;
//first, we sort the array in ascending order [small to large number]
void sort(int array_size,int array_elements[]){
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

// then we use recursion to find two or more subsets of the target value 
void find_subsets(int array_size, int array_elements[], int target_value, int index, int current_sum, int subset[], int subset_size){
	if (current_sum==target_value && subset_size>=2){
		for (int counter=0;counter<subset_size;counter++){
			cout<<subset[counter]<<" ";
		}
		cout<<endl;
		return;
	}
	if (index>=array_size || current_sum>target_value){
		return;
	}

	//including current element
	subset[subset_size]=array_elements[index];
	find_subsets(array_size, array_elements, target_value, index+1, current_sum+array_elements[index], subset, subset_size+1);

	//excluding current element
	find_subsets(array_size, array_elements, target_value, index+1, current_sum, subset, subset_size);
}

void subsets(int array_size, int array_elements[],int target_value){
	int subset[100]; //temporary array to store the current subset
	find_subsets(array_size, array_elements, target_value, 0, 0, subset, 0);
}

int main(){
	//getting inputs 
	int array_size,array_elements[100],target_value;
	cout<<"Enter the size of the array: ";
	cin>>array_size; 
	cout<<"Enter the elements of the array: ";
	for (int counter=0;counter<array_size;counter++){
		cin>>array_elements[counter]; 
	}
	cout<<"Enter the target value: ";
	cin>>target_value;
	sort(array_size,array_elements);
	subsets(array_size,array_elements,target_value); 
}
