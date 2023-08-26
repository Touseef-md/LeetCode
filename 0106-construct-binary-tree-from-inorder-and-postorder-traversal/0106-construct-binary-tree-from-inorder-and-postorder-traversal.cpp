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
    int c;
    void solve(vector<int>& inorder,vector<int>& postorder,int i,int j,TreeNode** root){
        if(i>j||c<0){
            return;
        }
        int k=j;
        while(inorder[k]!=postorder[c]){
            k--;
        }
        *root=new TreeNode(postorder[c--]);
        solve(inorder,postorder,k+1,j,&((*root)->right));
        solve(inorder,postorder,i,k-1,&((*root)->left));
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        c=postorder.size()-1;
        TreeNode* node;
        solve(inorder,postorder,0,c,&node);
        return node;
    }
};