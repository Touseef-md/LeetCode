class Solution {
public:
    vector<vector<int>> dp;
    // map<pair<int,vector<int>>,int> mp;
    int solve(int i,vector<int>& currSum,vector<int>& cookies,int &k){
        if(i==cookies.size()){
            int maxi=0;
            for(auto it:currSum){
                maxi=max(maxi,it);
            }
            return maxi;
        }
        // auto it=mp.find({i,currSum});
        // if(it!=mp.end()){
        //     return it->second;
        // }
        int mini=INT_MAX;
        for(int j=0;j<k;j++){
            currSum[j]+=cookies[i];
                mini=min(mini,solve(i+1,currSum,cookies,k));
            currSum[j]-=cookies[i];
        }
        return mini;
        // return mp[{i,currSum}]=mini;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        dp.clear();
        int n=cookies.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        vector<int> currSum(k,0);
        return solve(0,currSum,cookies,k);
    //     int mini=INT_MAX;
    //     for(int i=0;i<k;i++){
    //         mini=min(mini,dp[0][i]);
    //     }
    //     return mini;
    }
};