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
    TreeNode* solve(vector<int>& preorder,int i,int j){
        if(i>=preorder.size()){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[i]);
        // i+=1;
        int k=i;
        while(k<preorder.size()&&preorder[k]<=preorder[i]){
            k++;
        }
        if(i+1<k&&i+1<=j)
            node->left=solve(preorder,i+1,k-1);
        if(k<=j)
        node->right=solve(preorder,k,j);
        // if(k==preorder.size()){
        //  node->left=solve(preorder,i+1);   
        // }
        // else{
        //     if(i+1<k){
        //         node->left=solve(preorder,i+1);
        //     }
        //     node->right=solve(preorder,k);
        // }
        // if(i<preorder.size()&&preorder[i]<=preorder[i-1])
            // node->left=solve(preorder,i);
        // if(i<preorder.size()&&preorder[i]>preorder[i-1])
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return solve(preorder,index,preorder.size()-1);
    }
};