class Solution {
public:
    // vector<vector<int>> dp;
    unordered_map<string,int> dp;
    bool solve(vector<int>& stones,unordered_map<int,int>&mp,int i,int step){
        if(i==stones.size()-1){
            return true;
        }
        // if()
        if(step==0||i>=stones.size()){
            return false;
        }
        string st=to_string(i)+"_"+to_string(step);
        auto it2=dp.find(st);
        if(it2!=dp.end()){
            return dp[st];
        }
        // int j=i+1;
        bool result=false;
        auto it=mp.find(stones[i]+step);
        if(it!=mp.end()){
            result|=solve(stones,mp,mp[stones[i]+step],step);
        }
        it=mp.find(stones[i]+step+1);
        if(it!=mp.end()){
            result|=solve(stones,mp,mp[stones[i]+step+1],step+1);
        }
        it=mp.find(stones[i]+step-1);
        if(it!=mp.end()){
            result|=solve(stones,mp,mp[stones[i]+step-1],step-1);
        }
        return dp[st]=result;
        // while()
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1||stones[1]-stones[0]<1){
            return false;
        }
        int n=stones.size();
        // dp.resize(n+1,);
        dp.clear();
        unordered_map<int,int> mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        return solve(stones,mp,1,1);
    }
};