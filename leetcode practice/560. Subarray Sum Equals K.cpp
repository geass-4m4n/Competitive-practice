class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size();
        if(n<1)return 0;
       map<int,int>m;
        m[0]=1;
        int ans=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(m.find(sum-k)!=m.end())
                ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
        
    }
};
