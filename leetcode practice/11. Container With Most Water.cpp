class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size();
        if(n<2)
            return 0;
        
        int ans=0,l=0,r=n-1;
        while(l<r)
        {
            int area=min(a[l],a[r])*(r-l);
            ans=max(ans,area);
            if(a[l]<a[r])
                l++;
            else
                r--;
        }
        
        return ans;
        
    }
};
