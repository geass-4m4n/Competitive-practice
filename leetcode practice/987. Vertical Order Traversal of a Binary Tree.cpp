class Solution {
    map<int,vector<pair<int,int>>> mp;
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.first==b.first)
            return a.second<b.second;
        else
            return a.first<b.first;
    }
    void dfs(TreeNode* root, int hd, int c){
        if(!root)
            return;
        mp[hd].push_back({c,root->val});
        dfs(root->left,hd-1,c+1);
        dfs(root->right,hd+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
         if(!root)
            return ans;
        
        dfs(root,0,0);
        
        for(auto x:mp){
            sort(x.second.begin(),x.second.end(),cmp);
            vector<int> v;
            for(auto y:x.second){
                v.push_back(y.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
