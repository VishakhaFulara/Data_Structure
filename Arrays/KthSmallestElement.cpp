//Randomized Quick select
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int Partition(int a[],int start,int end){
    	int pivot=a[end];
	    int pindex=start;									//set partition index as start initially 
	    for(int i=start;i<end;i++){
	    	if(a[i]<pivot){
		    	swap(a[i],a[pindex]);					//Swap if element is lesser than pivot
		    	pindex++;
	    	}
	    }
	    swap(a[pindex],a[end]);
    	return pindex;
	}
  //Randomise function to slect random pivot element between l & r
    int RandomPartition(int arr[],int l,int r){
        int n=r-l+1;
        int pivot=rand()%n;
        swap(arr[l+pivot],arr[r]);
        return Partition(arr,l,r);
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
       if(k>0 && k<=r-l+1){
        int pindex=RandomPartition(arr,l,r);
        
        if(pindex-l==k-1)
            return arr[pindex];
        if(pindex-l>k-1)
            return kthSmallest(arr,l,pindex-1,k);
        else
            return kthSmallest(arr,pindex+1,r,k-1-pindex+l);
        }
        return INT_MAX;
    }
};

 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
