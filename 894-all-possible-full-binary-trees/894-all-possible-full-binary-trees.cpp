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
    unordered_map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> Sol(int n){
        if(n%2==0){
            return {};
        }
        if(n==1){
            return {new TreeNode(0)};
        }
        auto it=dp.find(n);
        if(it!=dp.end()){
            return dp[n];
        }
        vector<TreeNode*> result;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left=Sol(i);
            vector<TreeNode*> right=Sol(n-1-i);
            // cout<<"LEFT "<<left.size()<<endl;
            // cout<<"RIGHT "<<right.size()<<endl;
            for(auto l:left){
                for(auto r:right){
                    // cout<<"INSIDE"<<endl;
                    TreeNode* newNode=new TreeNode(0,l,r);
                    result.push_back(newNode);
                }
            }
        }
        // cout<<n<<"  "<<result.size()<<endl;
        return dp[n]=result;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        dp.clear();
        return Sol(n);
    }
};