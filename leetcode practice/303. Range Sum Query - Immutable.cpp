vector<int>sum(10005,0);
class NumArray {
public:
   
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum[i+1]=sum[i]+nums[i]; 
        sum[n+1]=sum[n];
        sum[n+2]=sum[n+1];
        
                // for(int i=0;i<=n;i++)
                //     cout<<sum[i]<<" ";cout<<endl;
        

        
    }
    
   
    
    int sumRange(int i, int j) {
        i++;
        j++;
        return (sum[j]-sum[i-1]); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
