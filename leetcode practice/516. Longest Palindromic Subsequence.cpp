class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int> > dp(n,vector<int>(n,0));int i,j,cl;
        
         for (i = 0; i < n; i++) 
      dp[i][i] = 1;
        
        for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (s[i] == s[j] && cl == 2) 
               dp[i][j] = 2; 
            else if (s[i] == s[j]) 
               dp[i][j] = dp[i+1][j-1] + 2; 
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
        } 
    } 
        
        return dp[0][n-1];
        
    }
};
