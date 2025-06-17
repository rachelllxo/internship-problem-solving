#include<iostream>
using namespace std;
int main(){
	int n,price[100];
	cout<<"Enter the no.of days: ";
	cin>>n; 
	cout<<"Enter the prices for each day: ";
	for(int i=0;i<n;i++){ 
		cin>>price[i];
	}
	int profit=0;
	for(int i=1;i<n;i++){
		if(price[i]>price[i-1]){
			profit+=price[i]-price[i-1];
		}
	}cout<<"Maximum profit:"<<profit;
	return 0;
}