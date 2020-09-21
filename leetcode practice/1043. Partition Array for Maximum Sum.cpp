class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>sum(n+1,0);
        
        for(int i=0;i<n;i++)
        {int cm=0;
            for(int j=0;j<=i&&j<k;j++)
            {
                cm=max(cm,arr[i-j]);
                sum[i+1]=max(sum[i+1],cm * (j + 1) + sum[i - j]);
                
            }
        }
       return sum[n] ;
        
    }
};
