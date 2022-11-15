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
int lastLeafIndex=0;
int firstLeafIndex=0;
int totalLeafNodes=0;
void firstLeaf(TreeNode* root,int index){
    if(root==NULL){
        return;
    }
    firstLeafIndex=min(firstLeafIndex,index);
    firstLeaf(root->left,index-1);
}
int leftDepth(TreeNode* root){
    if(root==NULL)
        return 0;
    return 1+leftDepth(root->left);
}
int rightDepth(TreeNode* root){
    if(root==NULL)
        return 0;
    return 1+rightDepth(root->right);
}
void lastLeaf(TreeNode* root,int leafNodes){
    int left=leftDepth(root->left);
    int right=leftDepth(root->right);
    if(left==0||right==0){
        // if(left==0&&right==0){
        //     lastLeafIndex=index;
        //     return;
        // }
//         if(left==0){
//     
//             cout<<"assumed that not possible "<<root->val<<endl;
//             return;
//         }
        // lastLeafIndex=index-1;
        totalLeafNodes=leafNodes+1;
        return;
    }
    if(left>right){
        lastLeaf(root->left,leafNodes);
    }
    else if(left==right){
        int nodes=(int(pow(2,left)+0.5)-1)-(int(pow(2,left-1)+0.5)-1);
        // cout<<"Going right "<<root->val<<"  nodes"<<nodes<<endl;
        lastLeaf(root->right,leafNodes+nodes);
    }
    else{
        cout<<"NOt possible"<<endl;
    }
}
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int height=leftDepth(root);
        if(height==rightDepth(root)){
            return int(pow(2,height)+0.5)-1;
        }
        // firstLeafIndex=0;
        lastLeaf(root,0);
        // firstLeaf(root,0);
        height=leftDepth(root);
        
        // cout<<lastLeafIndex<<endl;
        // cout<<firstLeafIndex<<endl;
        // return lastLeafIndex-firstLeafIndex+1;
        // return int(pow(2,height-1)+0.5)-1+lastLeafIndex-firstLeafIndex+1;
        // cout<<totalLeafNodes<<endl;
        return int(pow(2,height-1)+0.5)-1+totalLeafNodes;
    }
};