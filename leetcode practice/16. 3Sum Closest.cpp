class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        
        
        sort(a.begin(),a.end());
        int n=a.size();
        if(n<3)
            return 0;
        
        int dif=INT_MAX;
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;int k=n-1;
            while(j<k)
            {
                if(a[i]+a[j]+a[k]==t)
                    return(a[i]+a[j]+a[k]);
                
                
                else if(a[i]+a[j]+a[k]>t)
                {
                    if(abs(t-(a[i]+a[j]+a[k]))<dif )
                    {
                        dif=abs(t-(a[i]+a[j]+a[k]));
                        ans=a[i]+a[j]+a[k];
                    }
                    k--;
                }
                    else
                        {
                        if(abs(t-(a[i]+a[j]+a[k]))<dif )
                    {
                        dif=abs(t-(a[i]+a[j]+a[k]));
                        ans=a[i]+a[j]+a[k];
                    }j++;
                    }
            }
        }
        
        return ans;

        
        
    
        
    }
};
