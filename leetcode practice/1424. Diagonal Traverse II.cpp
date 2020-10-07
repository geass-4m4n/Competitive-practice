class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        map<int,vector<int> >m;
        int n=a.size();
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                m[i+j].push_back(a[i][j]);
            }
        }
        
        
        for(auto it=m.begin();it!=m.end();it++)
        {
            vector<int>k=(*it).second;
            
            for(int i=k.size()-1;i>=0;i--)
                ans.push_back(k[i]);
        }
        
        return ans;
    }
};
