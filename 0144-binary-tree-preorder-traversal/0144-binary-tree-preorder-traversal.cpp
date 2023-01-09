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
    vector<int> result;
    void preorder(TreeNode* root){
        if(root==NULL)
            return;
        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       //------------------ Recursive Solution //
        // if(root==NULL)
        //     return {};
        // result.clear();
        // preorder(root);
        // return result;
        //----------------- Iterative Solution //---------
            if(root==NULL)
            return {};
        result.clear();
        queue<TreeNode*> left;
        stack<TreeNode*> right;
        left.push(root);
        TreeNode* temp;
        while(right.size()>0||left.size()>0){
            if(left.size()>0){
                temp=left.front();
                left.pop();
                result.push_back(temp->val);
                if(temp->left!=NULL){
                    left.push(temp->left);
                }
                if(temp->right!=NULL){
                    right.push(temp->right);
                }
            }
            else if(right.size()>0){
                temp=right.top();
                right.pop();
                result.push_back(temp->val);
                if(temp->left!=NULL){
                    left.push(temp->left);
                }
                if(temp->right!=NULL){
                    right.push(temp->right);
                }
            }
        }
        return result;
    }
};