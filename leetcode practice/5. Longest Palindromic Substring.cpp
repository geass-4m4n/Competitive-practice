class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();int ans=0;
        string res="";
        if(n==0) return res;
        if(n==1) return s;
        
        if(n==2) 
        {
            if(s[0]==s[1])
            {
                return s;
            }
            else
            { res+=s[0];
                return res;
            }
        }
        
        int mx=0,ml=0,mr=0;
        
        for(int i=0;i<=2*n-1;i++)
        { int ans=0;
            int l=i/2;
            int r=l+i%2;
            while(l>=0 && r<n && s[r]==s[l]){ans++;if(r!=l)ans++;;l--;r++;}
          if(ans>mx)
          {
              mx=ans;
              ml=l+1;
              mr=r-1;
          }
        }
        
       for(int i=ml;i<=mr;i++)
           res+=s[i];
        
        return res;
        
    
        
    }
};
