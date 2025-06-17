#include<iostream>
#include<climits>
using namespace std;
int main(){
	int n,price[100];
	cout<<"Enter the no.of days: ";
	cin>>n; 
	cout<<"Enter the prices for each day: ";
	for(int i=0;i<n;i++){ 
		cin>>price[i];
	}
	int min_price=INT_MAX; 
	int max_profit= 0; 
	for(int i=0;i<n;i++){
		min_price = min(min_price, price[i]);
		int profit = price[i] - min_price; 
		max_profit = max(profit, max_profit); 
	}
	cout<<"The maximum profit is: "<<max_profit; 
}