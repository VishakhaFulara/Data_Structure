class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     /*
     int len=nums.size();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(nums[i]==nums[j])
                    return nums[i];
            }
        }
        return -1;*/
      //time -O(n),space -0(n)  
        set<int>s;
        int len=nums.size();
        set<int>::iterator itr;
        for(int i=0;i<len;i++){
            itr=s.find(nums[i]);
            if(itr==s.end()){
                s.insert(nums[i]);
            }
            else
                return nums[i];
        }
        return -1;
    }
};
