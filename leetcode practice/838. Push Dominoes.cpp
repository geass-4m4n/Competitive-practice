class Solution {
public:
    string pushDominoes(string s) {
        int n=s.length();
        vector<int>r(n,-1);
        
        int c=-1;
        
        for(int i=0;i<n;i++)
        {
          if(s[i]=='R'){c=1;r[i]=c;;continue;}
          if(s[i]=='L'){c=-1;r[i]=c;continue;}
            if(c==-1)continue;
            r[i]=++c;
        }
        
         vector<int>l(n,-1);
        
        c=-1;
        
        for(int i=n-1;i>=0;i--)
        {
          if(s[i]=='L'){c=1;l[i]=c;;continue;}
          if(s[i]=='R'){c=-1;l[i]=c;continue;}
            if(c==-1)continue;
            l[i]=++c;
        }
        
        for(int i=0;i<n;i++)
        {
            if(l[i]==-1 && r[i]==-1)continue;
            
            if(l[i]==-1){s[i]='R';continue;}
            if(r[i]==-1){s[i]='L';continue;}
            
            if(l[i]<r[i])s[i]='L';
            else if(r[i]<l[i])s[i]='R';
            else
                continue;
        }
        
        return s;
        
    }
};
