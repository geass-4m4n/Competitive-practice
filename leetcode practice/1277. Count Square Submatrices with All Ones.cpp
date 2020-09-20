class Solution {
public:
    int countSquares(vector<vector<int>>& ma) {
        if(ma.size()==0)
            return 0;
        if(ma[0].size()==0)
            return 0;
        int n=ma.size();
        int m=ma[0].size();        int ans=0;
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(ma[i-1][j-1]==0)continue;
                
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                ans=ans+dp[i][j];
            }
        }
        
        return ans;
        
    }
};
