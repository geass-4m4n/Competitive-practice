class Solution {
public:
    int mincostTickets(vector<int>& d, vector<int>& c) {
        
        int n=d.size();
        vector<int>dp(d[n-1]+1,0);
        set<int>s(d.begin(),d.end());
        
        for(int i=1;i<=d[n-1];i++)
        {
            if(!s.count(i))dp[i]=dp[i-1];
            else
                dp[i]=min(min(dp[i-1]+c[0], dp[max(0,i-7)]+c[1]),dp[max(i-30,0)]+c[2]);
        }
        
        return dp[d[n-1]];
        
    }
};
