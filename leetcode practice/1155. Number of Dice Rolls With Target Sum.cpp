class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d+1, vector<int>(target+1, 0));

   dp[0][0] = 1;

   
   for (int i = 1; i <= d; i++) {
      for (int t = 1; t <= target; t++) {
         for (int face = 1; face <= f; face++) {
            if ((t-face) < 0) continue;
            dp[i][t] = (dp[i][t] + dp[i-1][t-face]) % 1000000007;
         }
      }
   }

   return dp[d][target];
        
    }
};
