class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = i + 1;
            for (int j = i + 2; j < n; ++j) {
                while(k < j && nums[i] + nums[k] <= nums[j]) {
                    ++k;
                }
                ans += j - k;
            }
        }
        return ans;
        
    }
};
