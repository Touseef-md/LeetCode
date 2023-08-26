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
    TreeNode* result;
    bool solve(TreeNode* root,int&val){
        if(root==NULL){
            return false;
        }
        if(root->val==val){
            result=root;
            return true;
        }
        bool left=solve(root->left,val);
        if(left){
            return true;
        }
        bool right=solve(root->right,val);
        if(right)
            return true;
        return false;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
     solve(root,val);
        return result;
    }
};