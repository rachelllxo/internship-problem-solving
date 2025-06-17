#include<iostream>
using namespace std;
int main(){
	int array_size;
	cout<<"Enter the size of the array: ";
	cin>>array_size;
	int arr[array_size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    int k;
	cout<<"Enter the value of k: ";
	cin>>k; 
	for(int i=0;i<s;i+=k){
		int start=i; 
		int end=i+k-1; 
		if (end>=s){
		end=s-1;
	}
	while(start<end){
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
	}
	}	cout<<"Reversed array: ";
	for(int i=0;i<s;i++){
	cout<<arr[i]<<" ";
	} 	
	return 0; 
	
}