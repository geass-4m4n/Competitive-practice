class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        
        vector<vector<int> > dp (n,vector<int>(m,0));
        
        if(a[0][0]==0)
        dp[0][0]=1;
        
      
        
        for(int i=1;i<n;i++)
            if(a[i][0]==0)
            dp[i][0]=dp[i-1][0];
        
        for(int j=1;j<m;j++)
            if(a[0][j]==0)
            dp[0][j]=dp[0][j-1];
        
        for(int i=1;i<n;i++)
         for(int j=1;j<m;j++)
             if(a[i][j]==0)
             dp[i][j]=dp[i-1][j]+dp[i][j-1];
        
        return dp[n-1][m-1];
        
    }
};
