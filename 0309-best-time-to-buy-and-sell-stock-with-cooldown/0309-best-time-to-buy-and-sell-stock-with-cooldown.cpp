class Solution {
public:
    int maxProfit(vector<int>& prices) {
              int max_profit=0,n=prices.size(),maxi=INT_MAX;
        vector<int> dp(n);
        vector<int> maxi_prof(n,0);
        for(int i=n-1;i>=0;i--){
            max_profit=0;
            for(int j=i;j<n;j++){
                if(j+2<n){
                    // max_profit=dp[j+2];
                max_profit=max(max_profit,prices[j]-prices[i]+maxi_prof[j+2]);
                }
                else{
                    max_profit=max(max_profit,prices[j]-prices[i]);
                }
            }
            dp[i]=max_profit;
            if(i+1<n)
                maxi_prof[i]=max(maxi_prof[i+1],dp[i]);
            else
                maxi_prof[i]=dp[i];
        }
        return maxi_prof[0];
    }
};