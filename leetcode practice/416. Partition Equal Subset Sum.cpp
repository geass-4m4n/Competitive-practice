class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        bool dp[n + 1][subSetSum + 1];
        memset(dp, 0, (n + 1) * (subSetSum + 1) * sizeof(bool));
        dp[0][0] = true;
        
    
        
        for(int j=0;j<=subSetSum;j++)
        {
            for(int i=1;i<=n;i++)
            {
                int curr=nums[i-1];
                if(j<curr)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j] = dp[i - 1][j] || (dp[i - 1][j - curr]);
                    
            }
        }
        return dp[n][subSetSum];
        
    }
};
