//Move all the negative elements to one side of the array 
#include <iostream>
using namespace std;

void separate(int a[],int n){
    int i=0,j=n-1;
    while(i<j){
	 
	 //if both are -ve numbers
        if(a[i]<0 && a[j]<0){
            i++;
            if(a[i]>0){
                swap(a[i++],a[j--]);
            }
        }
	    
	//if both are positive numbers
        else if(a[i]>0 && a[j]>0){
            j--;
            if(a[j]<0){
                swap(a[i++],a[j--]);
            }
        }
	    
	 //if one +ve & other is -ve
        else if(a[i]>0 &&  a[j]<0){
            swap(a[i++],a[j--]);
        }
        else{
            i++;
            j--;
        }
    }
}
int main() {
    int n;
    cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	separate(arr,n);
	for(int i=0;i<n;i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}
