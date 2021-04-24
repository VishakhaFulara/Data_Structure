#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
  
        if(arr[0]==0)
            return -1;
        if(n<=1)
            return 0;
        
        int max_reach=arr[0],jump=1,step=arr[0],i;
        
        for(i=1;i<n;i++){
            if(i==n-1)
                return jump;
            
            max_reach=std::max(max_reach,i+arr[i]);
            step--;
            
            if(step==0){
                jump++;
                
                if(i>=max_reach)
                    return -1;
                
                //update the step    
                step=max_reach-i;
            }
        }
        return -1;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
