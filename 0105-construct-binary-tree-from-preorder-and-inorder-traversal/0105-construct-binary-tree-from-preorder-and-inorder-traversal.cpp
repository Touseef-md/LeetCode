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
    void solve(vector<int>&preorder,vector<int>& inorder,TreeNode** node,int i,int j,int k,int l){
        if(j<i){
            return;
        }
        // cout<<((*node)->val)<<endl;
        *node=new TreeNode(preorder[i]);
        int elements,p;
        for(p=k;p<=l;p++){
            if(inorder[p]==preorder[i]){
                elements=p-k;
                break;
            }
        }
        // return;
        solve(preorder,inorder,&((*node)->left),i+1,i+elements,k,p-1);
        solve(preorder,inorder,&((*node)->right),i+elements+1,j,p+1,l);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode(5);
        solve(preorder,inorder,&root,0,preorder.size()-1,0,inorder.size()-1);
        return root;
    }
};