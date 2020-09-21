class Solution {
public:
    vector<vector<int> >dp;
    vector<int>ps;
    
     int solve(int i,int m,vector<int> piles)
    {
        if(i>=piles.size()) 
            return 0;
         
         
        if(dp[i][m]!=-1)return dp[i][m];
         
        int ans=1e9,res=0;
        for(int x=1;x<=m*2;x++)
        {
            ans=min(ans,solve(i+x,max(m,x),piles));
        }
        res=ps[i]-ans;
        dp[i][m]=res;
        return res;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        ps.resize(n,0);ps[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ps[i]=ps[i+1]+piles[i];
        }
        return solve(0,1,piles);
        
    }
};
