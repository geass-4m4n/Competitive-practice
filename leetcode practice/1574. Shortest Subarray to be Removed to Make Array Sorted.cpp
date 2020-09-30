class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
         int l=0, r=arr.size()-1,n=arr.size();
        
        while(l < r and arr[l+1] >= arr[l])
             l+=1;
        
        if(l == n-1) return 0;
        
        while( r > 0 and arr[r-1] <= arr[r])
              r-=1;
        
        
        int lentoRemove = min((n-l-1), r);

        for(int i=0;i<l+1;i++)
        {
            if(arr[i] <= arr[r])
                lentoRemove = min(lentoRemove,(r-i-1));
            else if(r < n-1)
                r += 1;
            else
                break;
        }
        return lentoRemove;
        
    }
};
