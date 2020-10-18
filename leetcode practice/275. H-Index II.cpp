class Solution {
public:
    int hIndex(vector<int>& a) {
        
        int n=a.size();
        vector<int>ps(n+1,0);
        
        for(int i=0;i<n;i++)
            ps[i+1]=ps[i]+a[i];
        
        int l=0,h=n-1;
        int ans=0;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(a[m] >= (n-m)) 
                h = m - 1;
            else 
                l = m + 1;
                
        }
        
        return n-l;
        
    }
};
