//sort an array of 0's,1's and 2's.

#include<iostream>
using namespace std;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void sort012(int a[], int n)
{
    // Dutch national flag algo 
    
    int low=0,high=n-1,mid=0;
    while(mid<=high){
        if(a[mid]==0){
            swap(&a[low],&a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==2){
            swap(&a[mid],&a[high]);
            high--;
        }
        else
            mid++;
    }
}
int main() 
{ 
	int n;
	cout<<"enter size:";
	cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin>> arr[i];
  
    sort012(arr, n); 
    cout << "array after sorting ";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 

  
    
