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
    TreeNode* solve(vector<int>& nums,int i, int j){
        if(i>j){
            return NULL;
        }
        int midIndex=(i+j)/2;
        TreeNode* mid=new TreeNode(nums[midIndex]);
        mid->left=solve(nums,i,midIndex-1);
        mid->right=solve(nums,midIndex+1,j);
        return mid;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};