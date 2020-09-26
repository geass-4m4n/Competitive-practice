class Solution {
public:
    
        int dp[20][2001];
   int s;
    
    int solve(int i,int n,vector<int>&a,long long tot)
    {
        if(i==n)
        {
            if(s==tot)
                return 1;
            return 0;
        }
        
        if(dp[i][tot] !=-1)return dp[i][tot];
        
        int ans=0;
        int a1=solve(i+1,n,a,tot+a[i]);
        int b=solve(i+1,n,a,tot-a[i]);
        
        ans=ans+a1+b;
        
        return dp[i][tot]=ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int n=nums.size();
        if(n==0)return 0;
        if(n==1){if(abs(S)==abs(nums[0]))return 1;else return 0; }
        
         if(S > 1000 || S < -1000)
            return 0;
        
        for(int i = 0; i<nums.size(); i++)
            for(int j = 0; j<=2000; j++)
                dp[i][j] = -1;
        
        s=S+1000;
        
        int ans=solve(0,n,nums,1000);
        
        return ans;
        
    }
};
