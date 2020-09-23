class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n=a.size();
        if(n<3)
            return n;int ans=0;
        
        vector<vector<int> > dp(n,vector<int>(505,1));
        
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int dif=a[i]-a[j];
                if(dif<0)continue;
                
                dp[i][dif]=max(dp[i][dif],1+dp[j][dif]);
                ans= max(ans,dp[i][dif]);
                
            }
        }
        
        reverse(a.begin(),a.end());
        
        vector<vector<int> > dp1(n,vector<int>(505,1));
        
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int dif=a[i]-a[j];
                if(dif<0)continue;
                
                dp1[i][dif]=max(dp1[i][dif],1+dp1[j][dif]);
                ans= max(ans,dp1[i][dif]);
                
            }
        }
        
        return ans;
        
    }
};

/*
class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n=a.size();
        if(n<3)
            return n;int ans=0;
        
        vector<vector<int> > dp(n,vector<int>(1010,1));
        
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int dif=a[i]-a[j];
                if(dif<0){
                    int kl=abs(dif);
                    dif=505+kl;
                }
                
                dp[i][dif]=max(dp[i][dif],1+dp[j][dif]);
                ans= max(ans,dp[i][dif]);
                
            }
        }
        
      
        return ans;
        
    }
};*/
