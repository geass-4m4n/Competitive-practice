class Solution {
public:
    void trim(string &s)
    {
        
        reverse(s.begin(),s.end());
            while(s[0]==' ')
                s.erase(s.begin());
        reverse(s.begin(),s.end());
            while(s[0]==' ')
                s.erase(s.begin());
        bool f=true;
        for(int i=0;i<s.length();i++)
        { 
            //cout<<s[i]<<" ";
            if(s[i]==' ')
            {  //cout<<i<<" "<<f<<endl;
                if(f)
                {
                    f=false;
                }
                else
                {s.erase(s.begin()+i);
               // cout<<"g";
                 i--;}
            }
            else
                f=true;
        }
        
                
    }
    string reverseWords(string s) {
        string ans="";
        trim(s);
        int n=s.length();
        if(n<2)
            return s;
        s=s+" ";
        n=s.length();
        string t="";
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(s[i] == ' ')
            {
                ans=t+" "+ans;
                t="";
                continue;
            }
            
            t=t+s[i];
        }
        
        ans.erase(ans.end()-1);
        return ans;
        
    }
};
