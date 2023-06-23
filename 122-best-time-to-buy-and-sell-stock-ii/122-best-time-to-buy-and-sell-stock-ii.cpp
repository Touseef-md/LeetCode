class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices,int i,int buy){
        if(i==prices.size()){
            if(buy==0){
                return prices[i-1];
            }
            return 0;
        }
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy==1){
            return dp[i][buy]=max(maxProfit(prices,i+1,buy),maxProfit(prices,i+1,0)-prices[i]);
        }
        else{
            return dp[i][buy]=max(maxProfit(prices,i+1,buy),maxProfit(prices,i+1,1)+prices[i]);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        dp.clear();
        dp.resize(prices.size(),vector<int>(2,-1));
        return maxProfit(prices,0,1);
    }
};