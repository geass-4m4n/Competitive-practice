class Solution {
public:
   vector<vector<int>> dp;
    int solve(int i,int j,vector<int>& A)
    {
        if(j-i+1<3)
            return 0;
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        for(int k=i+1;k<j;k++)
        {
            dp[i][j]=min(dp[i][j],A[i]*A[j]*A[k]+solve(i,k,A)+solve(k,j,A));
        }
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& A) {
        int n=A.size();
        dp.resize(n,vector<int>(n,INT_MAX));
        return solve(0,n-1,A);
    }
};
