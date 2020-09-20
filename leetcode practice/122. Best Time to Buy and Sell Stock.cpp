class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
       int  n=prices.size();
        int mp=prices[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            int dif=mp-prices[i];
            ans=max(ans,dif);
            mp=max(mp,prices[i]);
        }
        
        return ans;
        
    }
};
