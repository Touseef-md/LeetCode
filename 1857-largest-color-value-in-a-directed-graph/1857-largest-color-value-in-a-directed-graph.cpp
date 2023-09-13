class Solution {
public:
    int result=0;
    vector<int> dfs(vector<vector<int>>& adj_list,vector<int>& visit,vector<vector<int>>& dp,string& s,int i){   
        vector<int> freq(26,0);
        vector<int> temp;
        // int currentAns=0;
        visit[i]=1;
        for(auto neigh:adj_list[i]){
            if(visit[neigh]==1){
                temp=dp[neigh];
            }
            else{
                temp=dfs(adj_list,visit,dp,s,neigh);
            }
            for(int i=0;i<26;i++){
                freq[i]=max(freq[i],temp[i]);
                // currentAns=max(currentAns,freq[i]);
                result=max(result,freq[i]);
            }
        }
        freq[s[i]-'a']++;
        result=max(result,freq[s[i]-'a']);
        dp[i]=freq;
        return freq;
    }
    bool cycleDetect(vector<vector<int>>& adj_list,vector<int> &globalVisit,vector<int> &temp,int i){
        
        temp[i]=1;
        for(auto neigh:adj_list[i]){
            if(globalVisit[neigh]==1){
                // return true;
            }
            else{
                if(temp[neigh]==1){
                    return true;
                }
                else{
                    if(cycleDetect(adj_list,globalVisit,temp,neigh)){
                        return true;
                    }
                }
            }
        }
        globalVisit[i]=1;
        temp[i]=0;
        return false;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> adj_list(n);
        vector<int> globalVisit(n,0);
        vector<int> temp(n,0);
        for(int i=0;i<edges.size();i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
        }
        //Detecting cycle in directed graph
        for(int i=0;i<n;i++){
            if(cycleDetect(adj_list,globalVisit,temp,i)){
                return -1;
            }
        }
        
        
        vector<int> visit(n,0);
        result=0;
        vector<vector<int>> dp(n,vector<int> (26,0));
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                dfs(adj_list,visit,dp,colors,i);
            }
        }
        return result;
    }
};