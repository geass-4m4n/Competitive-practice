class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        
        int n=t.size();
        if(n==0)return 0;
        if(n==1)return t[0][0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<t[i].size();j++)
            {
                 int a=INT_MAX,b=INT_MAX;
                if(j-1>=0)
                    a=t[i-1][j-1];
                if(j>=0 && j<i)
                 b=t[i-1][j];
                
                
                int mn=min(b,a);
                
                t[i][j]+=mn;
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<t[n-1].size();i++)
            ans=min(ans,t[n-1][i]);
        
//           for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<t[i].size();j++)
//             {cout<<t[i][j]<<" ";
                
//             }cout<<endl;
//           }
        
        return ans;
    }
};
