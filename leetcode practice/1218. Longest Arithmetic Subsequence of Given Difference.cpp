class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        int n=a.size();
        if(n<2)return n;
        if(n==2){if(a[1]-a[0]==d)return 2; else return 1;}
        vector<int>dp(n,1);
        map<int,int>mp;
        mp[a[0]]=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            int x= a[i]-d;
            int v=mp[x];
            dp[i]=v+1;
            int o=mp[a[i]];
            mp[a[i]]=max(o,dp[i]);
            
            ans=max(ans,dp[i]);   
        }
        
        return ans;
        
    }
};
