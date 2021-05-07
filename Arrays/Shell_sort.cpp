#include<iostream>
#include<cmath>
using namespace std;

void shell_sort(int arr[],int n){

	for(int gap=n/2;gap>=1;gap/=2){
		for(int j=gap;j<n;j++){
			for(int i=j-gap;i>=0;){
				if(arr[i]>arr[i+gap])
					swap(arr[i],arr[i+gap]);
				else
					break;
				i=i-gap;
			}
		}
	}
	
}


int main(){
	int n;
	cout<<"enter size:";
	cin>>n;
	int arr[n];
	cout<<"enter array elements:";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	shell_sort(arr,n);
	
	cout<<"\nAfter sorting:";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
