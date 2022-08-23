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
    int number=0;
    void dfs(TreeNode* root,string &st){
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL){
            st+=to_string(root->val);
            number+=stoi(st);
            st.pop_back();
            return;
        }
        st+=to_string(root->val);
        dfs(root->left,st);
        dfs(root->right,st);
        st.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        dfs(root,s);
        return number;
    }
};