class Solution {
public:
    vector<vector<int>> dp;
    int sol(vector<int>& coins,int amount,int i){
        if(amount==0){
            return 1;
        }
        if(i<=0){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int result=0;
        if(coins[i-1]<=amount){
            result+=sol(coins,amount-coins[i-1],i);
        }
        return dp[i][amount]=result+sol(coins,amount,i-1);  
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.clear();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return sol(coins,amount,n);
    }
};