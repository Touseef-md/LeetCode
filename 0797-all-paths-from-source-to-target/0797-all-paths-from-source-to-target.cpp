class Solution {
public:
    vector<vector<int>> paths;
    int n;
    void dfs(vector<int>& path,int i,vector<vector<int>>& graph){
        if(i==n-1){
            path.push_back(n-1);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(i);
        for(auto j:graph[i]){
                dfs(path,j,graph);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        paths.clear();
        n=graph.size();
        // v[0]=0;
        dfs(path,0,graph);
        return paths;
    }
};