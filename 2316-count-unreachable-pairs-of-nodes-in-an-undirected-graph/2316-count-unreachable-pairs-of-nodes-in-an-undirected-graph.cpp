class Solution {
public:
    long long dfs(vector<vector<int>>& adj_list,vector<int> &visit,int i){
        long long count=0;
        visit[i]=1;
        for(auto j:adj_list[i]){
            if(visit[j]==0)
                count+=dfs(adj_list,visit,j);
        }
        return count+1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long rem=n,count=0;
        vector<vector<int>> adj_list(n);
        vector<int> visit(n,0);
        for(auto i:edges){
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        long long result=0;
        int m=n;
        for(int i=0;i<m;i++){
            if(visit[i]==0){
                count=dfs(adj_list,visit,i);
                result+=count*(n-count);
                n=n-count;
            }
        }
        return result;
    }
};