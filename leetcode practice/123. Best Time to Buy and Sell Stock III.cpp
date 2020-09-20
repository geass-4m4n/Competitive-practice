class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
        
        vector<int>a1(n,0);
        vector<int>a2(n,0);
        int mp=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int dif=mp-prices[i];
            a1[i]=max(a1[i+1],dif);
            mp=max(mp,prices[i]);
        }
        
        int np=prices[0];
        
        for(int i=1;i<n;i++)
        {
            int dif= prices[i]-np;
            a2[i]=max(a2[i-1],dif);
            np=min(np,prices[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,(a1[i]+a2[i]) );
        
        
        return ans;
        
        
        
    }
};
