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
    void Flatten(TreeNode* root){
        if(root==NULL){
            return;
        }
        Flatten(root->left);
        Flatten(root->right);
        // if(root->left==NULL&&root->right==NULL)
        //     return ;
        if(root->left==NULL){
            return ;
        }
        if(root->right==NULL){
            TreeNode* temp1=root->left;
            root->left=NULL;
            root->right=temp1;
            return;
        }
        TreeNode* temp1=root->left;
        TreeNode* temp2=root->right;
        root->left=NULL;
        root->right=temp1;
        while(temp1->right!=NULL)
            temp1=temp1->right;
        temp1->right=temp2;
        // return ;
    }
    void flatten(TreeNode* root) {
        Flatten(root);
    }
};