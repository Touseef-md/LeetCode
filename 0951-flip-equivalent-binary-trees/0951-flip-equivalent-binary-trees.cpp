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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2==NULL){
            return true;
        }
        if(root1 ==NULL || root2 ==NULL){
            return false;
        }
        if(root1->val != root2->val ){
            return false;
        }
        if(root1->left == NULL && root2->left ==NULL){
            return flipEquiv(root1->right, root2->right);
        }
        if(root1->right == NULL && root2->right ==NULL){
            return flipEquiv(root1->left, root2->left);
        }
        if(root1->left == NULL && root2->right == NULL){
            return flipEquiv(root1->right, root2->left);
        }
        if(root1->right == NULL && root2->left == NULL){
            return flipEquiv(root1->left, root2->right);
        }
        if(root1->left ==NULL ||root1->right ==NULL ||root2->left ==NULL ||root2->right ==NULL ){
            return false;
        }
        if( root1->left->val == root2->left->val){
            if(root1->right->val==root2->right->val){
                return flipEquiv(root1->left,root2->left) && flipEquiv(root1->right, root2->right);
            }
            else{
                return false;
            }
        }
        else if( root1->left->val == root2->right->val){
            if(root1->right->val == root2->left->val){
                return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
            }
            else{
                return false;
            }
        }
            return false ;
        
    }
};