class Solution {
public:
    
    int solve(int r,int c,vector<vector<int>>& a )
    {
        
        int ans=0;
        int mc=-1;
        for(int i=r;i>-1;i--)
            for(int j=c;j>mc;j--)
            {
                if(a[i][j])ans++;
                else
                    mc=j;
            }
        return ans;
    }
    int numSubmat(vector<vector<int>>& a) {
        
        int n=a.size();
         if(!n )
        return 0;
        int m=a[0].size();
        if(!m)
        return 0;
        
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                ans=ans+solve(i,j,a);
            }
        
        return ans;
        
        
    }
    
};
