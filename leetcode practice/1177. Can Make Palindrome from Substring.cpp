class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        
        int n = s.size();
            vector<vector<int>>ve(n, vector<int>(26, 0));
            ve[0][s[0] - 'a'] = 1;
            for(int i = 1;i<n;i++){
                ve[i]=ve[i-1];
                ve[i][s[i] -'a'] = ve[i -1][s[i] -'a'] + 1;
               
            }
        
        vector<bool> ret;
        for(int i = 0 ;i<queries.size();i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            if(l == r)
                ret.push_back(true);
            else{
                int count = 0;
                    
                if(l != 0)
                    {
                    for(int i = 0;i<26;i++)
                    {
                        if((ve[r][i] - ve[l-1][i])%2)
                        count++;
                    }
                    }
                
                else
                    {
                    for(int i = 0;i<26;i++)
                    {
                        if(ve[r][i] %2)
                            count++;
                    }
                    }
                
            if(count/2 <= k)ret.push_back(true); else ret.push_back(false);
            }
            
            }
        
        return ret;
        
    }
};
