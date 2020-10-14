/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(TreeNode* root, int sum,vector<int>&p,vector<vector<int> >&ans)
    {
       
        if(root==NULL)
            return;
        if(sum==root->val && root->left==NULL &&root->right==NULL)
        {p.push_back(root->val);ans.push_back(p);p.pop_back();return;}
        
        sum=sum-root->val;
        p.push_back(root->val);
        if(root->left)
        solve(root->left,sum,p,ans);
        if(root->right)
        solve(root->right,sum,p,ans);
        p.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int>p;
        solve(root,sum,p,ans);
        return ans;
    }
};
