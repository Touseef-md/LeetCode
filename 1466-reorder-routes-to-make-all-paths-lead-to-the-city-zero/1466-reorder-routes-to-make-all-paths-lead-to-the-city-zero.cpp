class Solution {
public:
    int count=0;
    int dfs(vector<vector<pair<int,int>>>& adj_list,vector<int>& visit,int i){
        int count=0;
        // cout<<"Check "<<i<<endl;
        visit[i]=1;
        for(auto j:adj_list[i]){
            if(visit[j.first]==1)
                continue;
            if(j.second==1){
                count+=1;
                count+=dfs(adj_list,visit,j.first);
            }
            else{
                count+=dfs(adj_list,visit,j.first);
            }
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj_list(n);
        for(auto i:connections){
            adj_list[i[0]].push_back({i[1],1});
            adj_list[i[1]].push_back({i[0],0});
        }
        vector<int> visit(n,0);
        count=0;
         return dfs(adj_list,visit,0);
        
    }
};