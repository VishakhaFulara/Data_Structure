//Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than 
//once in the given array.
#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
 
        vector<int>vec;
        int index;
        for(int i=0;i<n;i++){
            index=arr[i]%n;
            arr[index]+=n;
        }
        for(int i=0;i<n;i++){
            if((arr[i]/n)>=2){
                vec.push_back(i);
            }
        }
            
        if(vec.empty()){
            return {-1};
        }
        return vec;
    }
};



int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
