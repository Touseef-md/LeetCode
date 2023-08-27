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
    TreeNode* lca;
    bool LCA(TreeNode* &root,TreeNode* &p,TreeNode* &q){
        if(root==NULL){
            return false;
        }
        // if(root==p||)
        bool left=LCA(root->left,p,q);
        bool right=LCA(root->right,p,q);
        if(left&&right){
            lca=root;
            return false;
        }
        if(root==p||root==q){
            if(left||right){
                lca=root;
                return false;
            }
            return true;
        }
        if(left||right){
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root,p,q);
        return lca;
    }
};