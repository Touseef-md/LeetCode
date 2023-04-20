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
    int maxiLen=0;
    int count=0;
    unordered_map<TreeNode*,pair<int,int>> mp;
    void longestPath(TreeNode* root){
        if(root==NULL){
            mp[root]={0,0};
            count++;
            return;
        }
        // cout<<"entering"<<endl;
        longestPath(root->left);
        longestPath(root->right);
        // cout<<"ROOT val "<<count<<"  "<<root->val<<endl;
        int left=0,right=0;
        if(root->left!=NULL)
        left=mp[root->left].second+1;
        // cout<<"LEFT "<<left<<endl;
        if(root->right!=NULL)
        right=mp[root->right].first+1;
        // cout<<"RIGHT "<<right<<endl;
        maxiLen=max({maxiLen,left,right});
        mp[root]={(root->left!=NULL)?mp[root->left].second+1:0,(root->right!=NULL)?mp[root->right].first+1:0};
        count++;
        // cout<<"REturning "<<endl;
        return;
    }
    int longestZigZag(TreeNode* root) {
        maxiLen=0;
        longestPath(root);
        // longestPath(root->right);
        return maxiLen;
    }
};