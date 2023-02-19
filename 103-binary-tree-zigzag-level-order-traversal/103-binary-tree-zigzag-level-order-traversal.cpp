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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        stack<TreeNode*> left;
        stack<TreeNode*> right;
        left.push(root);
        int flag=0;
        vector<int> temp;
        vector<vector<int>> result;
        while(left.size()+right.size()>0){
            temp.clear();
            if(flag==0){
                while(left.size()>0){
                    TreeNode* node=left.top();
                    temp.push_back(node->val);
                    if(node->left!=NULL)
                    right.push(node->left);
                    if(node->right!=NULL)
                    right.push(node->right);
                    left.pop();
                }
                result.push_back(temp);
                flag=1;
            }
            else{
                flag=0;
                while(right.size()>0){
                    TreeNode* node=right.top();
                    temp.push_back(node->val);
                    if(node->right!=NULL)
                    left.push(node->right);
                    if(node->left!=NULL)
                    left.push(node->left);
                    right.pop();
                }
                result.push_back(temp);
            }
        }
        return result;
    }
};