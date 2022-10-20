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
    unordered_map<int,int> mp;
    bool dfs(TreeNode * root,int k){
        if(root==NULL)
            return false;
        auto it=mp.find(k-root->val);
        mp[root->val]++;
        if(it!=mp.end())
            return true;
        if(dfs(root->left,k)||dfs(root->right,k))
            return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,k);
        // return false;
    }
};