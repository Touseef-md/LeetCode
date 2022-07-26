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
    TreeNode* answer;
    bool foundAnswer=false;
    bool LCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL)
            return false;
        if(foundAnswer)
            return false;
        bool present=false,left=false,right=false;
        if((root->val==p->val)||(root->val==q->val))
            present=true;
        left=LCA(root->left,p,q);
        right=LCA(root->right,p,q);
        if((present&&left)||(present&&right)||(left&&right)){
            answer=root;
            foundAnswer=true;
            return false;
        }
        return present||left||right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root,p,q);
        // if(foundAnswer){
        //     cout<<"FOUND ANSWER"<<endl;
        // }
        return answer;
    }
};