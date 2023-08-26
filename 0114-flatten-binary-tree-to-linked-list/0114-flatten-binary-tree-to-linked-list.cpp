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
    void solve(TreeNode** root){
        if((*root)==NULL){
            return;
        }
        if((*root)->left==NULL&&(*root)->right==NULL){
            return;
        }
        solve(&((*root)->left));
        solve(&((*root)->right));
        if((*root)->left==NULL){
            return;
        }
        // cout<<(*root)->val<<endl;
        TreeNode* right=(*root)->right;
        TreeNode* leftRight=(*root)->left;
        TreeNode* temp=leftRight;
        while(leftRight!=NULL){
            if(leftRight->right){
                temp=leftRight;
                leftRight=leftRight->right;
            }
            else if(leftRight->left){
                temp=leftRight;
                leftRight=leftRight->left;
            }
            else{
                break;
            }
        }
        // cout<<"FDSF"<<endl;
        cout<<(*root)->val<<endl;
        // cout<<"TEMP "<<temp->val<<endl;
        // cout<<"RIGH T"<<right->val<<endl;
        leftRight->right=right;
        (*root)->right=(*root)->left;
        (*root)->left=NULL;
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return ;
        }
        // TreeNode* root;
        solve(&root);
        return ;
        
    }
};