class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res;
        for(int i=0;i<=num;i++)
        {
            int ans=0;
            int n=i;
            while(n)
            {
                if(n&1)ans++;
                n=n>>1;
            }
            res.push_back(ans);
            
            
        }
        
        return res;
        
    }
};
