class Solution {
public:
    vector<int> dp;
    bool solve(vector<int>& nums,int &n,int i){
        // int n=nums.size();
        if(i>=n){
            return true;
        }
        if(n-i<2){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        bool result=false;
        // cout<<i<<"test  "<<result<<endl;
        if(nums[i]==nums[i+1]){
            result|=solve(nums,n,i+2);
        }
        if(i+2<n){
            // cout<<i<<" Enter"<<endl;
            if(nums[i]==nums[i+1]&&nums[i+1]==nums[i+2]){
                result|=solve(nums,n,i+3);
            }
            if((nums[i+1]==nums[i]+1)&&(nums[i+1]+1==nums[i+2])){
                // cout<<"Entering third  "<<i<<endl;
                result|=solve(nums,n,i+3);
                // cout<<"result of third "<<result<<endl;
            }
        }
        // cout<<i<<" returning "<<result<<endl;
        return dp[i]=result;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        dp.clear();
        dp.resize(n+1,-1);
        return solve(nums,n,0);
    }
};