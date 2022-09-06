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
    bool Tree(TreeNode* root){
        if(root==NULL)
            return false;
        bool l=Tree(root->left),r=Tree(root->right);
        // cout<<root->val<<" Stary "<<l<<"  "<<r<<endl;
        if(l==false){
            
            if(root->left!=NULL)delete(root->left);
            root->left=NULL;
        }
        if(r==false){
            
        if(root->right!=NULL)delete(root->right);
            root->right=NULL;
        }
        // bool a=(Tree(root->left)||Tree(root->right))
        // cout<<"END"<<endl;
        if(l||r){
            // cout<<root->val<<" left and right "<<l<<r<<endl;
        return true;
        }
        if(root->val==1)return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!Tree(root)){
            // cout<<"NULL nki"<<endl;
            return NULL;
        }
        // cout<<"NOT NULL "<<root->val<<endl;
        
        return root;
    }
};