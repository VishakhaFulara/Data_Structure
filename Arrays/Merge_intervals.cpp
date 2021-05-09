/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover 
all the intervals in the input.
 Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();
        if(n<=0)
            return {{-1,-1}};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>arr(n,vector<int>(2));
        int i,j=1,k=0,c=0;
        int temp1=intervals[0][1],temp2= intervals[0][0];
        for(i=1;i<n;i++){
            if(intervals[i][j-1]<=temp1){

                if( intervals[i][j]>temp1)
                    temp1= intervals[i][j];
            }
            else{
                arr[k][0]=temp2;
                arr[k][1]=temp1;
                k++;
                temp1= intervals[i][j];
                temp2= intervals[i][j-1];
                c++;
            }
        }
        c++;
        arr.resize(c,vector<int>(2));
        arr[k][0]=temp2;
        arr[k][1]=temp1;
        return arr;
    }
};
