class Solution {
public:
    vector<vector<int>> dp;
    int max_len_rep_subarray(vector<int>& nums1,vector<int>&nums2,int i,int j){
    if(i<0||j<0)
        return 0;
        // cout<<i<<"  "<<j<<endl;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(nums1[i]==nums2[j]){
            dp[i][j]=1+max_len_rep_subarray(nums1,nums2,i-1,j-1);
            max_len_rep_subarray(nums1,nums2,i-1,j);
            max_len_rep_subarray(nums1,nums2,i,j-1);
            return dp[i][j];
        }
        else{
            max_len_rep_subarray(nums1,nums2,i-1,j);
            max_len_rep_subarray(nums1,nums2,i,j-1);
            return dp[i][j]=0;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.clear();
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        max_len_rep_subarray(nums1,nums2,nums1.size()-1,nums2.size()-1);
        int maxi=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};