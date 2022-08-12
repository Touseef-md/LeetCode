/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca=NULL;
    bool LCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL)
            return false;
        bool left=false,right=false;
        if(root==p||root==q){
            left=true;
            right=LCA(root->left,p,q)||LCA(root->right,p,q);
            if(left&&right){
                lca=root;
                return true;
            }
            return left||right;
        }
        left=LCA(root->left,p,q);
        right=LCA(root->right,p,q);
        if(left&&right){
            lca=root;
            return true;
        }
        return left||right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root,p,q);
        return lca;
    }
};