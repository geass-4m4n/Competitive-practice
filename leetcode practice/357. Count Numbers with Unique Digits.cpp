class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
          long long dp[n + 1];
        dp[0]=1;
        for(int i = 1; i <= n; i++)
        {
            dp[i]=9;
            long long k = 9;
            long long count = 1;
            while(count < i)
            {
                dp[i] *= k;
                count++;
                k--;
            }
            dp[i] += dp[i - 1];
        }
            return dp[n];
        
    }
};
