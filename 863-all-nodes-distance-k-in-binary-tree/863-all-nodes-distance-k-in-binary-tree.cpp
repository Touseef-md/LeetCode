/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int value;
    unordered_map<int,int> mp;
    int rootToTargetDist(TreeNode* root,int &targetVal,int &subTree){
        if(root==NULL){
            return -1;
        }
        if(root->val==targetVal){
            mp[targetVal]=1;
            return 0;
        }
        int left=rootToTargetDist(root->left,targetVal,subTree);
        int right=rootToTargetDist(root->right,targetVal,subTree);
        if(left!=-1){
            subTree=0;
            mp[root->val]=1;
            return 1+left;
        }
        if(right!=-1){
            subTree=1;
            mp[root->val]=1;
            return 1+right;
        }
        return -1;
    }
    void searchBelow(TreeNode* root,vector<int>& result,int depth,int flag){
        if(root==NULL){
            return;
        }
        if(depth==0){
            if(root->val!=value)
            result.push_back(root->val);
            // return;
        }
        if(flag==1)
        {if(root->left!=NULL){
            if(mp[root->left->val]==1){
                searchBelow(root->left,result,depth-1,flag);
            }
            else{
                searchBelow(root->left,result,depth+1,flag);
            }
        }
            
        if(root->right!=NULL){
            if(mp[root->right->val]==1){
                searchBelow(root->right,result,depth-1,flag);
            }
            else{
                searchBelow(root->right,result,depth+1,flag);
            }
        }
        }
        else{
            searchBelow(root->left,result,depth-1,flag);
        searchBelow(root->right,result,depth-1,flag);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }
        value=target->val;
        mp.clear();
        int targetVal=target->val;
        int subTree=-1;
        int targetDist=rootToTargetDist(root,targetVal,subTree);
        vector<int> result;
        if(subTree==-1){
            searchBelow(target,result,targetDist-k,1);
        }
        else{
            //Search below the target
            searchBelow(root,result,targetDist-k,1);
            // if(k!=0){
            //     //Search above the target
            //     if(targetDist-k>=0){
            //         searchBelow(root,result,targetDist-k,1);
            //     }
            //     if(k>targetDist){
            //         //Search in second subtree
            //         if(subTree==0){
            //             searchBelow(root->right,result,k-targetDist-1,0);
            //         }
            //         else{
            //             searchBelow(root->left,result,k-targetDist-1,0);
            //         }
            //     }
            // }
        }
        return result;
    }
};