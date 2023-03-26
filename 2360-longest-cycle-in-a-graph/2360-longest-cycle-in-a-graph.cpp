class Solution {
public:
    int dfs(vector<int>& edges,vector<int>& nodeCount,vector<int>&visited,int i,int counter){
        if(i==-1)
            return -1;
        if(visited[i]==1){
            return counter-nodeCount[i];
        }
        if(visited[i]==2){
            return -1;
        }
        visited[i]=1;
        nodeCount[i]=counter;
        int ans=-1;
        ans=dfs(edges,nodeCount,visited,edges[i],counter+1);
        // if(ans==-1)
            // return -1;
        visited[i]=2;
        return ans;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> visited(n,0);
        vector<int> nodeCount(n);
        // vector<vector<int>> adj_list(n);
        int ans,result=-1;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans=dfs(edges,nodeCount,visited,i,0);
                // if(ans!=-1){
                    // return ans;
                // }
                result=max(result,ans);
            }
        }
        return result;
    }
};