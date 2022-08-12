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
    void inorder(TreeNode* root,vector<int>& traversal){
        if(root==NULL)
            return;
        inorder(root->left,traversal);
        traversal.push_back(root->val);
        inorder(root->right,traversal);
    }
    bool isValidBST(TreeNode* root){
        vector<int> inorder_travel;
        inorder(root,inorder_travel);
        int n=inorder_travel.size();
        if(n==1)
            return true;
        int x=inorder_travel[0];
        for(int i=1;i<n;i++){
            if(inorder_travel[i]>x){
                x=inorder_travel[i];
            }
            else
                return false;
        }
        return true;
    }
    // APPROACH 1:NOT ABLE TO GET ACCEPTED
    // long long int value=INT_MIN-5;
    // bool isValidBST(TreeNode* root) {
    //     if(root==NULL)
    //         return true;
    //     if(root->left==NULL&&root->right==NULL){
    //         if(root->val>value){
    //             value=root->val;
    //             return true;
    //         }
    //         return false;
    //     }
    //     if(isValidBST(root->left)){
    //         if(root->val>value){
    //             value=root->val;
    //             if(isValidBST(root->right))
    //                 return true;
    //             return false;
    //         }
    //         return false;
    //     }
    //     return false;
    // }
};