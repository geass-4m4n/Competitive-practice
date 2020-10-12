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
    int mod=1000000007;
public:
    
    int solve(TreeNode* root,long long int &ans,long long int sum)
    {
        if(root==NULL)
            return 0;
        int l=solve(root->left,ans,sum);
        int r=solve(root->right,ans,sum);
        int c=root->val%mod;;
        
        
       
        ans=max(ans, max( (l*(sum-l)),(r*(sum-r))) );
        return(l+r+c);
    }
    
    int tot(TreeNode*root)
    {
        if(root==NULL)
            return 0;
        
        int l=tot(root->left);
        int r=tot(root->right);
        int c=root->val;
        return (l+c+r);
    }
    int maxProduct(TreeNode* root) {
        long long int ans=0;
        long long int sum=tot(root);
        int l=solve(root,ans,sum);
        return ans%mod;
    }
};
