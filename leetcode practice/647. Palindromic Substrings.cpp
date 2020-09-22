class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();int ans=0;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) 
        {
            if(s[0]==s[1])
            {
                return 3;
            }
            else
            {
                return 2;
            }
        }
        
        for(int i=0;i<=2*n-1;i++)
        {
            int l=i/2;
            int r=l+i%2;
            while(l>=0 && r<n && s[r]==s[l]){ans++;l--;r++;}
        }
        
        return ans;
        
    }
};
