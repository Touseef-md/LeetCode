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
#include<bits/stdc++.h>
class Solution {
public:
    int maxi=INT_MIN;
    unordered_map<TreeNode*,vector<TreeNode*>> adjlist;
    int dfs_max_path(TreeNode* root){
        if(root==NULL)
            return 0;
        int value=INT_MIN;
        for(auto it=adjlist[root].begin();it!=adjlist[root].end();it++){
            value=max(value,dfs_max_path(*it));
        }
        // int value=dfs(root->left);
        // value=max(value,dfs(root->right));
        // value>=root->rig
        if(value==INT_MIN)
            value=0;
        return root->val+value;
    }
    // void dfs(TreeNode* root){
    //     if(root==NULL)
    //         return;
    //     if(root->left==NULL&&root->right==NULL)
    //         return;
    //     if(root->left!=NULL){
    //         adjlist[root].push_back(root->left);
    //         adjlist[root->left].push_back(root);
    //     }
    //     if(root->right!=NULL){
    //         adjlist[root].push_back(root->right);
    //         adjlist[root->right].push_back(root);
    //     }
    //     dfs(root->left);
    //     dfs(root->right);
    // }
    int dfs(TreeNode* root){
        if(root==NULL)
            return 0;
        int value=root->val;
        int a=dfs(root->left);
        int b=dfs(root->right);
        value=max(value,root->val+a);
        value=max(value,root->val+b);
        // value=max(value,root->val+a+b);
        maxi=max(maxi,value);
        maxi=max(maxi,root->val+a+b);
        return value;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxi;
        // cout<<"CHECK"<<endl;
        int maxi=INT_MIN;
        for(auto it=adjlist.begin();it!=adjlist.end();it++){
            maxi=max(maxi,dfs_max_path(it->first));
        }
        return maxi;
        // for(auto it:adjlist){
        //     for(auto i:it.second)
        //     dfs_max_path(it)
        // }
    }
};