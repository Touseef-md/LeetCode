class Solution {
public:
    // int buyAndSel
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][0]=max(dp[i+1][1]+prices[i],dp[i+1][0]);
            dp[i][1]=max(dp[i+1][0]-prices[i]-fee,dp[i+1][1]);
        }
        //9,9 
        //,0
        return dp[0][1];
//         int flag=0,n=prices.size(),profit=0,cost=0;
//         if(n<=1)
//             return 0;
//         for(int i=0;i<n-1;i++){
//             if(i==n-2){
//                 if(flag==1){
//                     if(prices[n-1]>=prices[i]){
//                         profit+=prices[n-1];
//                     }
//                     else{
//                         profit+=prices[i];
//                         // flag=0;
//                     }
//                 }   
//                 else{
//                     if(prices[i]+fee<=prices[i+1]){
//                         profit=profit-prices[i]-fee+prices[i+1];
//                     }
//                 }
//                 break;
//             }
//             if(flag==0){
//                 if(prices[i]+fee<=prices[i+1]){
//                     flag=1;
//                     profit-=prices[i];
//                     profit-=fee;
//                     cost=prices[i]+fee;
//                 }
//             }
//             else{
//                 if(prices[i]<=prices[i+1]){
//                     // continue;
//                 }
//                 else{
//                     if(cost==prices[i]){
                        
//                     }
//                     flag=0;
//                     profit+=prices[i];
//                 }
                
//             }
//             cout<<i<< " "<<profit<<endl;
            
//         }
//         // if(prices[i]>=prices[i-1])
//         //     return profit+prices[i];
//         return profit;
    }
};