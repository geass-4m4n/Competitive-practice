class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        
        int odd_count = 0, even_count = 0;
        vector<int> temp = nums;
        
        
        for (int i = 1; i < nums.size(); i += 2) 
        {
            if (i == nums.size() - 1) {
                if (nums[i] <= nums[i - 1]) {
                    odd_count += (nums[i - 1] - nums[i] + 1);
                    nums[i - 1] = nums[i] - 1;
                }
            } else {
                if (nums[i] <= nums[i - 1]) {
                    odd_count += (nums[i - 1] - nums[i] + 1);
                    nums[i - 1] = nums[i] - 1;
                }
                if (nums[i] <= nums[i + 1]) {
                    odd_count += (nums[i + 1] - nums[i] + 1);
                    nums[i + 1] = nums[i] - 1;
                }
            }
        }
        
        
        nums = temp;
        for (int i = 0; i < nums.size(); i += 2) {
            if (i == 0) {
                if (nums[i] <= nums[i + 1]) {
                    even_count += (nums[i + 1] - nums[i] + 1);
                    nums[i + 1] = nums[i] - 1;
                }
            } else if (i == nums.size() - 1) {
                if (nums[i] <= nums[i - 1]) {
                    even_count += (nums[i - 1] - nums[i] + 1);
                    nums[i - 1] = nums[i] - 1;
                }
            } else {
                if (nums[i] <= nums[i - 1]) {
                    even_count += (nums[i - 1] - nums[i] + 1);
                    nums[i - 1] = nums[i] - 1;
                }
                if (nums[i] <= nums[i + 1]) {
                    even_count += (nums[i + 1] - nums[i] + 1);
                    nums[i + 1] = nums[i] - 1;
                }
            }
        }
        
        return min(odd_count, even_count);
        
    }
};
