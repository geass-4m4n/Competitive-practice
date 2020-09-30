class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        
        long long int mx1=0,mx2=0;
        int n=ho.size(),m=ve.size();
        sort(ho.begin(),ho.end());
        sort(ve.begin(),ve.end());
        
        mx1=max(mx1,(long long)ho[0]);
        mx1=max(mx1,(long long)h-ho[n-1]);
        
        mx2=max(mx2,(long long)ve[0]);
        mx2=max(mx2,(long long)w-ve[m-1]);
        
        for(int i=1;i<n;i++)mx1=max(mx1,(long long)ho[i]-ho[i-1]);
        for(int i=1;i<m;i++)mx2=max(mx2,(long long)ve[i]-ve[i-1]);
        
        int mod=(int)1e9+7;
        return (mx1*mx2)%mod;
        
    }
};
