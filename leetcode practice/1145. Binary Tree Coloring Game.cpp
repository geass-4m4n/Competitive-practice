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
    
    void findrp(TreeNode* root,TreeNode** p,TreeNode** r,TreeNode*pr,int x)
    {
        if(root==NULL)
            return;
        if(root->val==x)
        {
            *p=pr;
            *r=root;
            return;
        }
        
        findrp(root->left,p,r,root,x);
        findrp(root->right,p,r,root,x);
        
    }
    int coun(TreeNode* r)
    {
        if(r==NULL)
            return 0;
        
        int l=coun(r->left);
        int ri=coun(r->right);
        return l+ri+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        TreeNode* p=NULL;
        TreeNode* r=NULL;
        if(root==NULL)
            return true;
        findrp(root,&p,&r,NULL,x);
        
        int ri=coun(r->left);
        int l=coun(r->right);
        
        int pa= n-ri-l-1;
        
        int mx=max(pa,max(l,ri));
        int mn=min(pa,min(l,ri));
        int md= pa+l+ri-mx-mn;
        
        int a=1+md+mn;
        int b=mx;
        
        if(b>a)
            return true;
        return false;
        
    }
};
