class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)return 0;
        map<int,int>hash;
        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }
        int x=*max_element(nums.begin(),nums.end());
        int dp[x+1];
        memset(dp,0,sizeof(dp));
        dp[1]=hash[1];
        for(int i=2;i<=x;i++)
        {
            dp[i]=max(dp[i-2]+hash[i]*i,dp[i-1]);
        }
        return dp[x];
        
    }
};
