class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        unordered_map<int,int> dp;
        dp[0]=-1;
        int left=-1;
        int right=0;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            if(dp.count(sum-target)==1 && dp[sum-target]>=left)
            {
                left=i;
                ++count;
            }
            dp[sum]=i;
        }
        return count;
        
    }
};
