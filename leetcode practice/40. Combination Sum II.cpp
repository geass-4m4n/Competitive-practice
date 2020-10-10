class Solution {
public:
    
    void solve(vector<int>& arr, int t,int s,vector<int>r, set<vector<int> >&ans,int id)
    {
        if(s>t)
            return;
        if(s==t)
        {
            ans.insert(r);
            return;
        }
        if(id>=arr.size())
            return;
        for(int i=id;i<arr.size();i++)
        {
            r.push_back(arr[i]);
        
            solve(arr,t,s+arr[i],r,ans,i+1);
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int t) {
        
        vector<int>r;
        set<vector<int> >ans;
        sort(arr.begin(),arr.end());
        solve(arr,t,0,r,ans,0);
        
        vector<vector<int> >res(ans.begin(),ans.end());
        
        return res;
        
    }
};
