//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        int c1=0,c2=0,i;
        for(i=0;i<n;i++){
            if(arr[i]==0){
                c1++;
            }
            else{
                c2++;
            }
        }
        for(i=0;i<c1;i++){
            arr[i]=0;
        }
         for(i=c1;i<n;i++){
            arr[i]=1;
        }
       /* int low=0,high=n-1;
        while(low<=high){
            if(arr[low]==0){
                low++;
            }
            else{
                swap(arr[low],arr[high]);
                high--;
            }
        }*/
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
