class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        int n=a.size();
        if(n<2)return false;
        map<int,int>m;
        
        for(int i=0;i<n;i++)
        {
            int p=a[i];
            if(p<0)
            {
                int l=abs(p);
                int u=(l+k-1)/k;
                p=p+(k*u);
            }
            
            int r=p%k;
            //cout<<a[i]<<" "<<r<<endl;
            m[r]++;
        }
        
        if(m[0]%2==1)return false;
        
        cout<<"j";
        
        for(int i=1;i<k;i++)
        {
            if(k-i==i)
            {
                if(m[i]%2==1)return false;
            }
            
            if((m[i]!=m[k-i]))
                return false;
        }
        
        return true;
        
    }
};
