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
    bool comp(vector<int>& a,vector<int> & b){
        if(b[0]<a[0])
            return false;
        if(b[0]==a[0]){
            if(b[1]<a[1])
                return false;
            if(b[1]==a[1]){
                if(b[2]<a[2])
                    return false;
            }
            return true;
        }
        return true;
    }
class Solution {
public:
    vector<vector<int>> coordinate;
    void dfs(TreeNode* root,int x,int y){
        if(root==NULL)
            return;
        coordinate.push_back({x,y,root->val});
        if(root->left)
            dfs(root->left,x-1,y+1);
        if(root->right)
            dfs(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        sort(coordinate.begin(),coordinate.end(),comp);
        if(coordinate.size()==1){
            return {{coordinate[0][2]}};
        }
        // cout<<coordinate.size()<<"SIZW "<<endl;
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(coordinate[0][2]);
        // cout<<"COORDINTW "<<coordinate[0][0]<<coordinate[0][1]<<coordinate[0][2]<<endl;
        for(int i=1;i<coordinate.size();i++){
            // cout<<"COORDINATWE "<<coordinate[i][0]<<coordinate[i][1]<<coordinate[i][2]<<endl;
            if(coordinate[i][0]!=coordinate[i-1][0]){
                ans.push_back(temp);
                temp.clear();
                temp.push_back(coordinate[i][2]);
                // i--;
            }
            else{
                temp.push_back(coordinate[i][2]);
            }
        }
        ans.push_back(temp);
        return ans;
//         map<int,vector<int>> mp;
//         queue<pair<TreeNode*,int>> q;
//         q.push({root,0});
//         q.push({NULL,0});
//         int count=0;
//         while(q.size()!=1){
//             auto it=q.front();
//             q.pop();
//             if(it.first==NULL){
//                 count++;
//                 q.push(it);
//                 continue;
//             }
//             vector<int> n=mp[it.second];
//             if(count==n.size()){
//                 int x=mp[it.second][n.size()-1];
//                 mp[it.second].pop_back();
//                 mp[it.second].push_back(min(x,it.first->val));
//                 mp[it.second].push_back(max(x,it.first->val));
//             }
//             // else{
//                 mp[it.second].push_back(it.first->val);
//                 if(it.first->left){
//                     // cout<<"LEFT is "<<it.first->left->val<<endl;
//                     q.push({it.first->left,it.second-1});
//                 }
//                 if(it.first->right){
//                     // cout<<"RIGHT is "<<it.first->right->val<<endl;
//                     q.push({it.first->right,it.second+1});
//                 }
//             // }
            
//         }
//         vector<vector<int>> ans;
//         for(auto it=mp.begin();it!=mp.end();it++){
//             // for(int j=0;j<it->second.size();j++){
//             // sort(it->second.begin(),it->second.end());
//                 ans.push_back(it->second);
//                 // ans[it->first].push_back(mp->second[j]);
//             // }
//         }
//         return ans;
    }
};