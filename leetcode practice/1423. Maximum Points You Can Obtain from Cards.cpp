class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        
        int n=a.size();
        int m=n-k;
        int tot=0,sum=0;
        for(int i=0;i<n;i++)
            tot+=a[i];
        
        for(int i=0;i<m;i++)
            sum+=a[i];
        
        int mn=sum;
        for(int i=m;i<n;i++)
        {
            sum=sum-a[i-m];
            sum=sum+a[i];
            mn=min(sum,mn);
        }
        
        return tot-mn;
    }
};
