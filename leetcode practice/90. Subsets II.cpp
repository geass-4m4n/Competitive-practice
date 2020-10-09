class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums , vector<int> state, int start)
    
    {
        ans.push_back(state);
        for(int i = start ; i < nums.size(); i++){
            if(i>start && nums[i] == nums[i-1])
                continue;
            state.push_back(nums[i]);
            backtrack(ans,nums,state,i+1);
            state.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans = {};
        sort(nums.begin(),nums.end());
        backtrack(ans,nums,{},0);
        return ans;
    }
};
