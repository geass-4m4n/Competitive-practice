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
    
    void solve(TreeNode* root,int f,int &mx,int s )
    {
        if(root==NULL)
            return ;
        mx=max(mx,s);
        if(f)
        {solve(root->left,1-f,mx,1+s);
         solve(root->right,f,mx,1);
        return;
        }
        
        solve(root->right,1-f,mx,1+s);
        solve(root->left,f,mx,1);
    }
    int longestZigZag(TreeNode* root) {
        
        if(root==NULL)
            return -1;
        int mx=0;
        solve(root,0,mx,0);
        solve(root,1,mx,0);
        return mx;
    
    }
};
