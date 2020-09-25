vector<vector<int> > dp(100,vector<int>(100,-1));
class Solution {
public:
    int solve(vector<int>&n,int s,int e)
    {
        if(s==e)return n[s];
        if(dp[s][e]!=-1)return dp[s][e];
        int a=n[s]-solve(n,s+1,e);
        int b=n[e]-solve(n ,s,e-1);
        dp[s][e]=max(a,b);
        return dp[s][e];
    }
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums,0,nums.size()-1)>=0;
        
    }
};
