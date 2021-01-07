#include<iostream>
using namespace std; 
int findPeakElement(int arr[], int low, int high, int n)
{
    int mid = low + (high-low)/2;
    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid] >= arr[mid+1]))
    {
        return mid;
    }
    else
    {
        if(mid > 0 && arr[mid-1] > arr[mid])
        {
            return findPeakElement(arr, low, mid-1, n);
        }
        else
        {
            return findPeakElement(arr, mid+1, high, n);

        }
    }
}
int peakElement(int arr[], int n)
{
    return findPeakElement(arr, 0, n-1, n);
    
}

int main() 
{ 
    int n;
    cout<<"enter size:";
    cin>>n;
    int arr[n];
    cout<<"enter the elements:";
    for(int i=0;i<n;i++){
    	cin>>arr[i];
	}
    cout << "Index of a peak point is "
         << peakElement(arr, n); 
    return 0; 
} 
