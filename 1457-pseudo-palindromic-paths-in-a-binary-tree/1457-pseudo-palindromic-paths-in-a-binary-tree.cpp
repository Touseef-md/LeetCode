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
    int count=0;
    unordered_map<int,int> mp;
    void dfs(TreeNode* root,int path_count){
        if(root==NULL){
            // cout<<"REturning nuull"<<endl;
            return;
        }
        // cout<<root->val<<" sfsd "<<endl;
        if(root->left==NULL&&root->right==NULL){
            // cout<<"INSIDE termination"<<endl;
            mp[root->val]++;
            int odd_count=0;
            for(auto it=mp.begin();it!=mp.end();it++){
                // cout<<it->first<<" Second "<<it->second<<endl;
                if(it->second>0){
                    if(it->second%2!=0)
                        odd_count++;
                }
                if(odd_count>1){
                    mp[root->val]--;
                    return;
                }
            }
            if(path_count%2==0&&odd_count==0){
                count++;
                // cout<<count<<" A  "<<path_count<<endl;
            }
            else if(path_count%2!=0&&odd_count==1){
                count++;
                // cout<<count<<" B "<<path_count<<endl;
            }
            else{
                // cout<<" NOTHGIN "<<endl;
            }
            mp[root->val]--;
            return;
        }
        mp[root->val]++;
        dfs(root->left,path_count+1);
        // cout<<"GIN G right"<<endl;
        dfs(root->right,path_count+1);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,1);
        return count;
    }
};