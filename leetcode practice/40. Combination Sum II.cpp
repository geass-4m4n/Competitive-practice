class Solution {
public:
    
    void solve(vector<int>& arr, int t,int s,vector<int>r, vector<vector<int> >&ans,int id)
    {
        if(s>t)
            return;
        if(s==t)
        {
            ans.push_back(r);
            return;
        }
        if(id>=arr.size())
            return;
        for(int i=id;i<arr.size();i++)
        {
            if(i>id && arr[i]==arr[i-1])
                continue;
            if(arr[i]>t-s)
                continue;
            
            r.push_back(arr[i]);
        
            solve(arr,t,s+arr[i],r,ans,i+1);
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int t) {
        
        vector<int>r;
        vector<vector<int> >ans;
        sort(arr.begin(),arr.end());
        solve(arr,t,0,r,ans,0);
        
        
        return ans;
        
    }
};
