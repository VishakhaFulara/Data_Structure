//function to rotate the array
#include<iostream>
#include<vector>
using namespace std;
 void reverse(vector<int>& nums,int low,int high)
  {
        while(low<high && low>=0)
        {
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
        
  }
  void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        reverse(nums,0,n-(k%n)-1);
        reverse(nums,n-(k%n),n-1);
        reverse(nums,0,n-1);
 }
int main(){
	int n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	int k;
	cin>>k;
	rotate(nums,k);
	for(int i=0;i<n;i++)
	{
		cout<<nums[i];
	}
	return 0;
}
