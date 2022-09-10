class Solution {
public:
    vector<vector<vector<int>>> dp;
    int maxi=-1;
    int fun(int k,int flag,vector<int>&prices,int i){
        if(i>=prices.size())
            return 0;
        if(k==0)
            return 0;
        if(dp[i][k][flag]!=-1)
            return dp[i][k][flag];
        if(flag==1){
            int a=prices[i]+fun(k-1,0,prices,i+1);//selling this one
            int b=fun(k,1,prices,i+1);
                return dp[i][k][1]=max(a,b);     
        }
        else{
            int a=fun(k,1,prices,i+1)-prices[i];//buying this one
            int b=fun(k,0,prices,i+1);
            return dp[i][k][0]=max(a,b);
        }
    }
    void func(int k,int flag,vector<int>& prices,int i,int profit){
        // maxi=max(maxi,profit);
        // if(flag==0)
        if(i>=prices.size())
            return;
        if(k==0){
            maxi=max(maxi,profit);
            return;    
        }
        if(flag==1){
            maxi=max(maxi,profit+prices[i]);
            // dp[i][k][1]=maxi;
            func(k-1,0,prices,i+1,profit+prices[i]);//Selling now
            func(k,1,prices,i+1,profit);
            dp[i][k][1]=max(profit,profit+prices[i]);
        }
        else{
            maxi=max(maxi,profit-prices[i]);
            // dp[i][k][0]=maxi;
            func(k,1,prices,i+1,profit-prices[i]);//buying now 
            func(k,0,prices,i+1,profit);
            dp[i][k][0]=max(profit,profit-prices[i]);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        // if(2*k>prices.size()){
        //     int profit=0;
        //     for(int i=1;i<prices.size();i++){
        //         profit+=max(0,prices[i]-prices[i-1]);
        //     }
        //     return profit;
        // }
        dp.clear();
        dp.resize(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return fun(k,0,prices,0);
        return maxi;
    }
};