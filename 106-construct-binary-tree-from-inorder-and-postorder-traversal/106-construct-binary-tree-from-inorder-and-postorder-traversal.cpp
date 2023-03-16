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
    unordered_map<int,int> inorderm;
    unordered_map<int,int> postorderm;
    TreeNode* buildTree(vector<int>& inorder,int i,int j,vector<int>& postorder,int k,int l){
        if(i>j||k>l)
            return NULL;
        cout<<i<<"  "<<j<<"  "<<k<<"  "<<l<<endl;
        int inroot=inorderm[postorder[l]];
        int n=inorder.size();
        int post_prev_root=-1;
        for(int m=i;m<inroot;m++){
            post_prev_root=max(post_prev_root,postorderm[inorder[i]]);
        }
        // post_prev_root=(inroot-1>=0)?postorderm[inorder[inroot-1]]:-1;
        // if(inroo)
        // int post_next_root=(inroot+1<inorder.size())?postorderm[inorder[inroot+1]]:inorder.size();
        TreeNode* left=(post_prev_root==-1)?NULL:buildTree(inorder,i,inroot-1,postorder,k,post_prev_root);
        TreeNode* right=(post_prev_root==-1)?buildTree(inorder,inroot+1,j,postorder,k,l-1):buildTree(inorder,inroot+1,j,postorder,post_prev_root+1,l-1);
        TreeNode* node=new TreeNode(inorder[inroot]);
        node->left=left;
        node->right=right;
        return node;
        // return new TreeNode(5);
        // return;
    }
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int& rootInd,int i,int j){
        if(rootInd<0||i>j)
            return NULL;
        // cout<<"STarting "<<inorderm[postorder[rootInd]]<<endl;
        int inorderRoot=inorderm[postorder[rootInd]];
        TreeNode* root=new TreeNode(inorder[inorderRoot]);
        // cout<<i<<"  "<<j<<" root "<<inorder[inorderRoot]<<" "<<inorderRoot<<endl;
        // return NULL;
        if(inorderRoot+1<=j&&rootInd-1>=0){
            // cout<<"RIght called"<<endl;
        root->right=helper(inorder,postorder,--rootInd,inorderRoot+1,j);
        }
        if(i<=inorderRoot-1&&rootInd-1>=0)
        root->left=helper(inorder,postorder,--rootInd,i,inorderRoot-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* head=NULL;
        int n=inorder.size();
        inorderm.clear();
        postorderm.clear();
        for(int i=0;i<n;i++){
            inorderm[inorder[i]]=i;
            postorderm[postorder[i]]=i;
        }
        n--;
        // head=buildTree(inorder,0,n-1,postorder,0,n-1);
        // cout<<n<<endl;
        head=helper(inorder,postorder,n,0,n);
        // if(head==NULL){
        //     cout<<"NULL is present "<<endl;
        // }
        // else{
        //     cout<<"NO null";
        // }
        return head;
    }
};