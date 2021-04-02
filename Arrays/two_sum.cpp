/*//takes O(n^2) runtime
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int l=nums.size();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                     return result;
                }
            }
        }
         return result;
    }
};*/
//take O(n) runtime
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int diff;
        int l=nums.size();
        map<int,int>m;
        for(int i=0;i<l;i++){
            diff=target-nums[i];
            if(m.find(diff)!=m.end() && m.find(diff)->second!=i){
                result.push_back(i);
                result.push_back(m.find(diff)->second);
                return result;
            }
            m[nums[i]]=i;
        }
        return result;
    }
};
