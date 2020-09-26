class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int n=nums.size();
        int r1=100000,r2=100000;
        
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            if(nums[i]%3==1){r2=min(r2,nums[i]+r1);r1=min(nums[i],r1);}
             if(nums[i]%3==2){r1=min(r1,nums[i]+r2);r2=min(nums[i],r2);}       
        }
        
        if(sum%3==0)return sum;
        if(sum%3==1)return sum-r1;
        
        return sum-r2;
                
    }
};
