class Solution {
public:
    int dfs1(int&n,vector<vector<int>>& adj_list,vector<vector<int>>& rev_adj_list,vector<int>& visit,int i){
        // cout<<i<<endl;
        int temp_ans=0; 
        visit[i]=1;
        for(auto  neigh:adj_list[i]){
            if(visit[neigh]==0)
            temp_ans+=dfs1(n,adj_list,rev_adj_list,visit,neigh);
        }
        for(auto neigh:rev_adj_list[i]){
            if(visit[neigh]==0){
                temp_ans+=1;
                temp_ans+=dfs1(n,adj_list,rev_adj_list,visit,neigh);
            }
        }
        return temp_ans;
    }
    void dfs2(int &n,vector<vector<int>>& adj_list,vector<vector<int>>& rev_adj_list,vector<int>& visit,vector<int>& result,int i,int totalLen,int revs){
        
        visit[i]=1;
        result[i]=totalLen-2*revs+result[0];
        for(auto neigh:adj_list[i]){
            if(visit[neigh]==0){
                dfs2(n,adj_list,rev_adj_list,visit,result,neigh,totalLen+1,revs);
            }
        }
        for(auto neigh:rev_adj_list[i]){
            if(visit[neigh]==0){
                dfs2(n,adj_list,rev_adj_list,visit,result,neigh,totalLen+1,revs+1);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        int firstAns=0;
        vector<vector<int>> adj_list(n);
        vector<vector<int>> rev_adj_list(n);
        vector<int> visit(n,0);
        for(int i=0;i<edges.size();i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            rev_adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        firstAns=dfs1(n,adj_list,rev_adj_list,visit,0);
        vector<int> result(n);
        result[0]=firstAns;
        visit.clear();
        visit.resize(n,0);
        dfs2(n,adj_list,rev_adj_list,visit,result,0,0,0);
        // cout<<firstAns<<endl;
        return result;
        // return {};
    }
};