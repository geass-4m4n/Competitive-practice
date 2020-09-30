class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& a) {
        vector<vector<int> > ans;
        sort(a.begin(),a.end());
        int n=a.size();
        if(n<3)
            return ans;
        set<vector<int> >p;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;int k=n-1;
            while(j<k)
            {
                if(a[i]+a[j]+a[k]==0)
                {
                    vector<int>l={a[i],a[j],a[k]};
                    j++;
                    k--;
                    p.insert(l);
                }
                else if(a[i]+a[j]+a[k]>0)k--;
                    else
                        j++;
            }
        }
        
      for(auto it=p.begin();it!=p.end();it++)
          ans.push_back(*it);
        
        return ans;
    }
};
