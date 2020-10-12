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
    bool solve(TreeNode* root,long long int mi,long long int ma)
    {
        if(root==NULL)
            return true;
        
         bool l=true,r=true;
       
         if(root->left)
              if(root->val<=INT_MIN)
            l=false;
        else
         l=solve(root->left,mi,root->val-1);
        
        if(root->right)
            if(root->val>=INT_MAX)
                r=false;
            else
               r=solve(root->right,root->val+1,ma);
        
         if(root->val<=ma && root->val>=mi)
            if(r&&l)
                return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};
