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
    void BST(vector<int>& nums,int i,int j,TreeNode** root){
        if(i>j)
            return ;
        int mid=i+(j-i)/2;
        (*root)=new TreeNode(nums[mid]);
        BST(nums,i,mid-1,&((*root)->left));
        BST(nums,mid+1,j,&((*root)->right));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        BST(nums,0,nums.size()-1,&root);
        return root;
    }
};