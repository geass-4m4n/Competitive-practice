class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n<1)
            return 0;
        if(s[0]=='0')
            return 0;
        if(n==1)
            return 1;
        
        vector<int>d(n,0);
        d[0]=1;
        d[1]=1;
        int o=10*(s[0]-'0')+(s[1]-'0');
        
        if(s[1]=='0' && s[0] >= '3')
            return 0;
        if(o<=26 && s[1]!='0')
            d[1]=2;
        
        for(int i=2;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1'||s[i-1]=='2')
                    d[i]=d[i-2];
                else
                    return 0;
                continue;
            }
            if(s[i-1]=='0')
            {
                d[i]=d[i-1];
                    continue;
            }
            d[i]=d[i-1];
            int k=10*(s[i-1]-'0')+(s[i]-'0');
            if(k<=26)
                d[i]=d[i]+d[i-2];
        }
        return d[n-1];
        
    }
};
