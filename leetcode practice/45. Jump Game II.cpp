class Solution {
public:
    int jump(vector<int>& nums) {
        
            int n = nums.size(), ans = 0, reach = 0, newReach = 0;
        for(int i = 0; i < n; i++){
            if(i > reach) reach = newReach, ans++;
            newReach = max(newReach, i + nums[i]);
        }
        return ans;
        
    }
};
