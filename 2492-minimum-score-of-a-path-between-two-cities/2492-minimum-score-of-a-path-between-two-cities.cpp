class Solution {
public:
    // void dfs(vector<int> &dist,vector<int> &visit,vector<vector<int>> &adj_list,vector<vector<int>>& roads,int i){
    //     // if(i==dist.size()-1)
    //     // cout<<i<<"  dist is "<<dist[i]<<endl;
    //     for(auto edge_ind:adj_list[i]){
    //         if(!visit[edge_ind]){
    //             visit[edge_ind]=1;
    //             int to=roads[edge_ind][1]-1;
    //             int w=roads[edge_ind][2];
    //             if(dist[to]>=min({dist[to],w,dist[i]})){
    //                 dist[to]=min({dist[to],w,dist[i]});
    //                 dfs(dist,visit,adj_list,roads,to);
    //             }
    //         }
    //     }
    // }
    void dfs(vector<vector<int>>& adj_list,vector<int>& visit,int i){
        visit[i]=1;
        for(auto v:adj_list[i]){
            // cout<<v<<endl;
            if(!visit[v]){
                dfs(adj_list,visit,v);
            }
        }
    }
    int minScore(int n, vector<vector<int>> roads) {
        vector<int> dist(n,INT_MAX);
        vector<vector<int>> adj_list(n);
        // cout<<"Size is "<<adj_list.size()<<endl;
        // vector<int> visit(roads.size(),0); dfs on edges
        vector<int> visit(n,0);
        //---------------_DFS on edges
        // for(int i=0;i<roads.size();i++){
        //     adj_list[roads[i][0]-1].push_back(i);
        //     adj_list[roads[i][1]-1].push_back(i);
        // }
        // dfs(dist,visit,adj_list,roads,0);
        // int result=INT_MAX;
        // for(int i=0;i<visit.size();i++){
        //     if(visit[i]){
        //         result=min(result,roads[i][2]);
        //     }
        // }
        for(int i=0;i<roads.size();i++){
            // cout<<
            adj_list[roads[i][0]-1].push_back(roads[i][1]-1);
            adj_list[roads[i][1]-1].push_back(roads[i][0]-1);
            // vector<int> temp={0,1,1};
            // adj_list[0].push_back(temp);
        }
        dfs(adj_list,visit,0);
        int result=INT_MAX;
        for(int i=0;i<roads.size();i++){
            if(visit[roads[i][0]-1]||visit[roads[i][1]-1]){
                result=min(result,roads[i][2]);
            }
        }
        return result;
    }
};