class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int n=a.size();
        vector<int>ans(2,-1);
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            
            
            if(a[m]==t){ans[0]=m;h=m-1;}
            else if(a[m]>t)
                h=m-1;
            else if(a[m]<t)
                l=m+1;
        }
        
         l=0;
         h=n-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(a[m]==t){ans[1]=m;l=m+1;}
            else if(a[m]>t)
                h=m-1;
            else if(a[m]<t)
                l=m+1;
        }
        return ans;
    }
};
