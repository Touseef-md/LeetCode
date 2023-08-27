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
    vector<int> inorder;
    void inorderTr(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorderTr(root->left);
        inorder.push_back(root->val);
        inorderTr(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder.clear();
        inorderTr(root);
        if(inorder.size()<=1){
            return true;
        }
        // cout<<inorder.size()<<endl;
        for(int i=1;i<inorder.size();i++){
            // cout<<"LOOP"<<endl;
            // cout<<inorder[i]<<" ";
            if(inorder[i]<=inorder[i-1]){
                return false;
            }
        }
        return true;
    }
};