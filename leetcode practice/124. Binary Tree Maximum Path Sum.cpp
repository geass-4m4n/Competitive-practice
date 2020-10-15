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
    int solve(TreeNode* root,int &mx)
    {
         if(root==NULL)
            return 0 ;
         int l=solve(root->left,mx);
         int r=solve(root->right,mx);
        int c=root->val;
        
        int a1= l+r+c;
        int a3=max(l,r)+c;
        a1=max(a1,a3);
        int a2=max(c,a1);
        mx=max(mx,a2);
        
        int r1=max(l,r)+c;
        return max(r1,c);
    }
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL)
            return 0 ;
        
        int mx=INT_MIN;
         solve(root,mx);
        return mx;
    }
};
