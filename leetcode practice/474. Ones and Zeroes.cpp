class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
         int i, j, k, len=strs.size(), zeroes=0, ones=0;
        string str;
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(len+1, 0)));
        vector<pair<int, int>> aux(len, {0, 0});
        for(i=0; i<len; i++){
            str=strs[i];
            ones=zeroes=0;
            for(auto ch:str){
                if(ch-'0')
                    ones++;
                else
                    zeroes++;
            }
            aux[i]={zeroes, ones};
        }
        for(i=0; i<=m; i++){
            for(j=0; j<=n; j++){
                for(k=1; k<=len; k++){
                    zeroes=aux[k-1].first;
                    ones=aux[k-1].second;
                    if(i-zeroes>=0 && j-ones>=0)
                        dp[i][j][k]=max(dp[i][j][k-1], dp[i-zeroes][j-ones][k-1]+1);
                    else
                        dp[i][j][k]=dp[i][j][k-1];
                }
            }
        }
        return dp[m][n][len];
        
    }
};
