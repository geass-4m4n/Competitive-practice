class Solution {
public:
    int maxDistToClosest(vector<int>& a) {
        
        int n=a.size();
        
        vector<int>r(n,20005);
        vector<int>l(n,20005);
        
        int y=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                l[i]=0;
                y=i;
            }
            
            if(y==-1)continue;
            l[i]=i-y;
        }
        
         y=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]==1)
            {
                r[i]=0;
                y=i;
            }
            
            if(y==-1)continue;
            r[i]=y-i;
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int cur=min(l[i],r[i]);
            ans=max(ans,cur);
        }
        return ans;
        
        
        
        
        
        
    }
};
