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
    int count=0;
    void preorder(TreeNode* root,int maxi){
        if(root==NULL)
            return;
        if(root->val>=maxi)
            count++;
        preorder(root->left,max(maxi,root->val));
        preorder(root->right,max(maxi,root->val));
    }
    int goodNodes(TreeNode* root) {
        preorder(root,INT_MIN);
        return count;
    }
};