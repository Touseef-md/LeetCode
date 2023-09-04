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
    int result;
    int count=0;
    void solve(TreeNode* root,int& k){
        if(root==NULL){
            return;
        }
        solve(root->left,k);
        count++;
        if(count==k){
            result=root->val;
        }
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        count=0;
        solve(root,k);
        return result;
    }
};