class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> outdegree(n);
        vector<vector<int>> adj_list(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                outdegree[i]++;
                adj_list[graph[i][j]].push_back(i);
            }
        }
        queue<int> q;
        vector<int> result(n,0);
        for(int i=0;i<outdegree.size();i++){
            if(outdegree[i]==0){
                q.push(i);
                // result[i]=1;
            }
        }
        while(!q.empty()){
            int ver=q.front();
            q.pop();
            result[ver]=1;
            for(auto neigh:adj_list[ver]){
                outdegree[neigh]--;
                if(outdegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        vector<int> safe;
        for(int i=0;i<n;i++){
            if(result[i]==1){
                safe.push_back(i);
            }
        }
        return safe;
    }
};