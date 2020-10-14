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
    
    void solve(TreeNode* root, int sum,int & c)
    {
       
        if(root==NULL)
            return ;
        if(sum==root->val )
        {c++;}
        
        sum=sum-root->val;
        solve(root->left,sum,c);
            solve(root->right,sum,c);
      
    }
    int pathSum(TreeNode* root, int sum) {
        int count =0;
        
        if(root==NULL)
            return 0;
        solve(root,sum,count);
        
        count=count+pathSum(root->left,sum);
        count=count+pathSum(root->right,sum);
        return count;
        
    }
};
