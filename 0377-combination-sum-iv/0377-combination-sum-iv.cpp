class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        // dp[0][0]=1;
        vector<long long int> dp(target+1,0);
        dp[0]=1;
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=1;
        // }
        // for(int i=1;i<=n;i++){
        unsigned long long int count=0;
            for(int t=1;t<=target;t++){
                count=0;
                for(int j=0;j<n;j++){
                    if(t==nums[j]){
                        // cout<<t<<"  "<<dp[t]<<"  called1"<<endl;
                        // dp[t]+=1LL;
                        count++;
                    }
                    if(t-nums[j]>0){
                        // cout<<"Called12"<<endl;
                        // cout<<dp[t-nums[j]]<<endl;
                        // dp[t]+=dp[t-nums[j]];
                        count+=dp[t-nums[j]];
                    }
                }
                // cout<<dp[t]<<" sdfsdf"<<endl;
                dp[t]=count;
            }
            // break;
            // cout<<endl;
        // }
        return dp[target];
    }
};