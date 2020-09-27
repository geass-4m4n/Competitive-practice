class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return f(dp, 1, n);
    }
    int f(vector<vector<int>>& dp, int l, int r){
       
        if (l >= r) return 0;
        if (dp[l][r]) return dp[l][r];
        int res = INT_MAX;
        int cur = 0;
        for (int i = l; i <= r; i ++){
            cur = i + max(f(dp, l, i - 1), f(dp, i + 1, r));
            res = min(res, cur); 
        }
        return dp[l][r] = res;
    }
};
