class Solution {
public:
    int modd(int a,int k)
    {if(a>=0)
        return a%k;
        
     int l=abs(a);
     int r=(l+k-1)/k;
     return a+(r*k);
    }
    int subarraysDivByK(vector<int>& a, int k) {
        int n=a.size();
       if(n<1)
            return 0;
        map<int,int>mp;
        mp[0]=1;
        
         for(int i=0;i<n;i++)
             a[i]=modd(a[i],k);
      
        vector<int>dp(n,0);
        int s=0;
        int ans=0;
        for(int i=0;i<n;i++)
        { s=(s+a[i])%k;
         ans=ans+mp[s];
         mp[s]++;
        }
        
        return ans;
        
        
        
    }
};
