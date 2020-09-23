class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
      dp[0]=0;
      dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<i;j++){
            dp[i] = max(dp[i],max((i-j)*dp[j],(i-j)*j));
        }
    }
    
    return dp[n]; 
      
    }
};
