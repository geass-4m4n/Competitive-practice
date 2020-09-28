class Solution {
public:
    int maximumSum(vector<int>& arr) {
         int n = arr.size(), x = *max_element(arr.begin(), arr.end());
        if(x <= 0)
            return x;
        
        
        int dp[2][n];
        dp[0][0] = 0;
        dp[1][0] = arr[0];
        for(int i = 1; i < n; i++){
            dp[0][i] = max(dp[1][i-1], dp[0][i-1] + arr[i]);
            dp[1][i] = max(dp[1][i-1], 0) + arr[i];
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, max(dp[0][i], dp[1][i]));
        }
        
        return ans;
    }
};
