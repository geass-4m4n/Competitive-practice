class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        
        int n=a.size();
        int m=a[0].size();
        
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int mn=a[i-1][j];
                if(j>0)mn=min(a[i-1][j-1],mn);
                if(j<m-1)mn=min(a[i-1][j+1],mn);
                
                a[i][j]+=mn;
            }
        
        int ans=INT_MAX;
        for(int j=0;j<m;j++)
            ans=min(ans,a[n-1][j]);
        
        return ans;
        
    }
};
