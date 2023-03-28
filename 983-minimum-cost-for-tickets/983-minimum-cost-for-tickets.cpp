class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int>mp;
        int n=days.size();
        for(auto i:days){
            mp[i]=0;
        }
        vector<int> dp(366,0);
        for(int i=1;i<=365;i++){
            auto it=mp.find(i);
            if(it==mp.end()){
                dp[i]=dp[i-1];
            }
            else{
                int cost1,cost2,cost3;
                cost1=costs[0]+dp[i-1];
                cost2=(i-7>=0)?costs[1]+dp[i-7]:costs[1];
                cost3=(i-30>=0)?costs[2]+dp[i-30]:costs[2];
                dp[i]=min({cost1,cost2,cost3});
            }
        }
        return dp[365];
    }
};