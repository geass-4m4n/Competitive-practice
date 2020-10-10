class Solution {
public:
int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k>bloomDay.size())
            return -1;
        int l=INT_MAX,r=INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
        {
            l=min(l,bloomDay[i]);
            r=max(r,bloomDay[i]);
        }
    
    
        while(l<=r)
        {
            int mid=(l+r)/2;
            int countk=0;int ck=0;
            for(int i=0;i<bloomDay.size();i++)
            {
                if(bloomDay[i]<=mid)
                    ck++;
                else
                {
                    ck=0;
                }
                if(ck==k)
                {
                    countk++;
                    ck=0;
                }
            }
            if(countk>=m)
            {
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return l;
    }
};
