class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
           int ans = 100001, currSum = 0, preIndex = 0; 
        vector<int> f(arr.size() + 1, 100001);
        for (int i = 0; i < arr.size(); i++) {
            for (currSum += arr[i]; currSum > target; currSum -= arr[preIndex++]);
            if (currSum == target) {
                f[i + 1] = min(i + 1 - preIndex, f[i]);
                ans = min(ans, f[preIndex] + i + 1 - preIndex);
            } else {
                f[i + 1] = f[i];
            }
        }
        return ans >= 100001 ? -1 : ans;
        
    }
};
