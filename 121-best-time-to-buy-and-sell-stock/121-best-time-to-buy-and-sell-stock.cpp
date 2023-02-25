class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,n=prices.size(),maxi=prices[n-1];
        for(int i=n-1;i>=0;i--){
            profit=max(profit,maxi-prices[i]);
            maxi=max(maxi,prices[i]);
        }
        return profit;
    }
};