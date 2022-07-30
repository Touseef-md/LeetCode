class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int t=0,sumi=0,count0=0;
        vector<int> numbers;
        for(auto i:nums){
            if(i==0){
                count0++;
                continue;
            }
            sumi+=i;
            numbers.push_back(i);
        }
        if((sumi+target)%2!=0)
            return 0;
        int n=numbers.size();
        t=(sumi+target)/2;
        if(t<0){
            t=t-target;
        }
        vector<vector<int>> dp(n+1,vector<int>(t+1));
        dp[0][0]=1;
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        // cout<<t<<"TARGET"<<endl;
        // cout<<n<<"SIZE"<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=t;j++){
                // cout<<i<<" "<<j<<endl;
                if(numbers[i-1]<=j){
                    // cout<<"FIRST"<<endl;
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-numbers[i-1]];
                    // cout<<"FISRST END"<<endl;
                }
                else{
                    // cout<<"SECOND"<<endl;
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        // return 0;
        // return dp[n][t]+dp[n][t]*count0;
        // return dp[n][t]+ dp[n][t]*(int(pow(2,count0)+0.5)-1);
        return dp[n][t]*(int(pow(2,count0)+0.5));
        // return dp[n][t];
    }
};