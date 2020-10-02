class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        vector<vector<int> > ans;
        sort(a.begin(),a.end());
        int n=a.size();
        if(n<4)
            return ans;
        
        
        set<vector<int> >p;
        for(int o=0;o<n-3;o++)
        for(int i=o+1;i<n-2;i++)
        {
            int j=i+1;int k=n-1;
            while(j<k)
            {
                if(a[i]+a[j]+a[k]+a[o]==t)
                {
                    vector<int>l={a[o],a[i],a[j],a[k]};
                    j++;
                    k--;
                    p.insert(l);
                }
                else if(a[i]+a[j]+a[k]+a[o]>t)k--;
                    else
                        j++;
            }
        }
        
      for(auto it=p.begin();it!=p.end();it++)
          ans.push_back(*it);
        
        return ans;
        
    }
};
