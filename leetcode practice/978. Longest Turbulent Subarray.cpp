class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        
 int n = A.size(); 
        
        if(n==1) return 1;
        if(n==2) return A[0]!=A[1]?2:1;
        
        int maxL = 1;
        
        int l = 0;
        
        int curr;
        
        int next;
        for(int i=1;i<n;i++)
        {
            curr = A[i-1]>A[i]?1:(A[i-1]<A[i]?-1:0);
            
            if(i<n-1)next = A[i]>A[i+1]?1:(A[i]<A[i+1]?-1:0);
            
            if(curr==0)l=i;
            
            else if(i==n-1 || (curr*next!=-1))
            {
                maxL = max(maxL,i-l+1);
                l =i;
            }
        }
        
        return maxL;
    }
};
