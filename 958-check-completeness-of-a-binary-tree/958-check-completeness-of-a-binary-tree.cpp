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
    int flag=-1;
    int maxdepth=0;
    void depth(TreeNode* root,int currdepth){
        if(root==NULL){
            maxdepth=max(maxdepth,currdepth);
            return ;
        }
        depth(root->left,currdepth+1);
        depth(root->right,currdepth+1);
        
    }
    int checkCompleteness(TreeNode* root,int level){
        // cout<<root->val<<endl;
        if(root->left==NULL&&root->right==NULL)
            return 1;
        int left,right;
        if(root->left!=NULL)
            left=checkCompleteness(root->left,level+1);
        else
            left=0;
        if(root->right!=NULL)
            right=checkCompleteness(root->right,level+1);
        else
            right=0;
        
        if(left==-1||right==-1)
            return -1;
        if((left==0||right==0)&&flag==-1){
            flag=level;
        }
        else if(flag!=-1&&(left==0||right==0)){
            if(flag!=level)
                return -1;
        }
        if(right>left){
            return -1;
        }
        // if(right==left){
        else if(left!=int(pow(2,maxdepth-level-1)+0.5)-1){
                return -1;
            }
        // }
        return 1+left+right;
    }
    bool isCompleteTree(TreeNode* root) {
        // maxdepth=0;
        // depth(root,0);
        // int result=checkCompleteness(root,0);
        // flag=-1;
        // // cout<<"FLAg is "<<flag<<endl;
        // if(result==-1)
        //     return false;
        // return true;
        queue<TreeNode*> q;
        int flag=0;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(flag==0&&temp==NULL){
                flag=1;
                continue;
            }
            if(flag==1&&temp!=NULL)
                return false;
            if(temp==NULL)
                continue;
            q.push(temp->left);
            q.push(temp->right);
        }
        return true;
    }
};