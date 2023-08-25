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
    int maxi=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        int temp_max=max({root->val,root->val+left,root->val+right});
        maxi=max({maxi,temp_max,left+right+root->val});
        // maxi=max(maxi,root->val+max(left,right));
        return temp_max;
    }
    int maxPathSum(TreeNode* root) {
        maxi=INT_MIN;
        solve(root);
        return maxi;
    }
};