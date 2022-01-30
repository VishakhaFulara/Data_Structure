class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxp=0,minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
           if(prices[i]<minPrice)
           {
               minPrice=prices[i];
           }
           else if(prices[i]>maxp)
           {
               maxp=max(maxp,prices[i]-minPrice);
           }
        }
        return maxp;
    }
};
