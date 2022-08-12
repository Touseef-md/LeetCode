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
    // vector<vector<int>> dp;
    map<pair<TreeNode*,bool>,int> mp;
    int rob(TreeNode* root,bool flag=true) {
        if(root==NULL)
            return 0;
        auto it=mp.find({root,flag});
        if(it!=mp.end())
            return it->second;
        if(flag==false){
            return rob(root->left,true)+rob(root->right,true);
        }
        int maxi=max(root->val+rob(root->left,false)+rob(root->right,false),rob(root->left,true)+rob(root->right,true));
        return mp[{root,flag}]=maxi;
    }
};