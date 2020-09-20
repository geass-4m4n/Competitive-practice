class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
        int ans=0;
        int cp=prices[0];
        for(int i=1;i<n;i++)
        {
            int sp=prices[i];
            if(sp>=cp)
                ans=ans+sp-cp;
            
            cp=sp;
        }
        
        return ans;
    }
};
