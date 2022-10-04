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
    bool dfs(TreeNode* root,int sumi,int &target){
        if(root==NULL)
            return false;
        sumi+=root->val;
        if(sumi==target&&root->left==NULL&&root->right==NULL)
            return true;
        if(root->left){
            if(dfs(root->left,sumi,target))
                return true;
        }
        if(root->right){
            if(dfs(root->right,sumi,target))
                return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(dfs(root,0,targetSum))
            return true;
        return false;
    }
};