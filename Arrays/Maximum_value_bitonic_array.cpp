//Given an array Arr of N elements which is first increasing and then may be decreasing, find the maximum element in the array.

#include<iostream>
using namespace std; 
	
int findMaximum(int arr[], int n) {
	    
	int l=0,h=n-1,mid;
	while(l<=h){
	    mid=l+(h-l)/2;
	    if(arr[mid+1]>arr[mid]){
	        l=mid+1;
	    }
	    else if(arr[mid-1]>arr[mid]){
	        h=mid-1;
	    }
	    else{
	        return arr[mid];
	    }
	}
}

int main()  
{  
    int n;
	cout<<"enter the size:";
	cin>>n;
	int arr[n];
	cout<<"enter array elements:";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	} 
    cout << "The maximum element is " << findMaximum(arr,n);  
    return 0;  
}  
  
