class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n1=nums.size();
        if(n1<2)return n1;
        
        vector<int>p(n1,1);
        vector<int>n(n1,1);
        
        for(int i=1;i<n1;i++)
        {
            if(nums[i]>nums[i-1]){p[i]=n[i-1]+1;n[i]=n[i-1];}
            else if(nums[i]<nums[i-1]){n[i]=p[i-1]+1;p[i]=n[i-1];}
            else
            {p[i]=p[i-1];n[i]=n[i-1];}
        }
        
        
        return max(p[n1-1],n[n1-1]);
        
        
        
    }
};
