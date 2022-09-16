class Solution {
public:
    vector<vector<int>>dp;
    int fun(vector<int>&nums,vector<int>& multipliers,int i,int j,int k){
        if(k>=multipliers.size())
            return 0;
        if(i>j)
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int a=multipliers[k]*nums[i];
        int b=multipliers[k]*nums[j];
            return dp[i][k]=max(a+fun(nums,multipliers,i+1,j,k+1),b+fun(nums,multipliers,i,j-1,k+1));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp.clear();
        // dp.resize(nums.size(),vector<int>(multipliers.size(),-1));
        // return fun(nums,multipliers,0,nums.size()-1,0);
        // dp.resize(multipliers.size()+1,vector<int>(multipliers.size()+1,0));
        dp.resize(multipliers.size()+1,vector<int>(3,0));
        for(int k=multipliers.size()-1;k>=0;k--){
            for(int i=k;i>=0;i--){
                int a=nums[i]*multipliers[k];
                int b=nums[nums.size()-1-k+i]*multipliers[k];
                // if(i+1<multipliers.size())
                    dp[i][k%2]=max(a+dp[i+1][(k+1)%2],b+dp[i][(k+1)%2]);
            }
        }
        return dp[0][0];
    }
};