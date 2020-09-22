class Solution {
public:
    int minimumDeleteSum(string a, string b) 
    {
    int n=a.size(), m=b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        dp[0][0]=0;
        
        for(int j=1; j<=b.size(); ++j){
            dp[0][j]= (int)b[j-1]+dp[0][j-1];
        }
        
        for(int i=1; i<=a.size(); ++i){
            dp[i][0]= (int)a[i-1]+dp[i-1][0];
        }
        
        for(int i=1; i<=a.size(); ++i){
            for(int j=1; j<=b.size(); ++j)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]= min((int)b[j-1]+dp[i][j-1], (int)a[i-1]+dp[i-1][j]);
            }
        }
       return dp[n][m];
    }
};
