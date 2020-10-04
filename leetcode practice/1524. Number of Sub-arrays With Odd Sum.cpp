class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
         int ans{};
        int odd{};
        int even{1};
        const int MOD = 1e9+7;
        int sum{};
        
        for (const auto num: arr) {
            sum += num;
            if (sum%2 == 1) {
                ans += even;
                ++odd;
            } else {
                ans += odd;
                ++even;
            }
            if (ans >= MOD) ans -= MOD;
        }
        
        return ans;
        
    }
};
