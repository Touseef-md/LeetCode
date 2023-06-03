class Solution {
public:
    int minTime=INT_MIN;
    void dfs(vector<vector<int>>& adj_list,vector<int>& informTime,int node,int time ){
        
        int flag=0;
        for(auto it:adj_list[node]){
            dfs(adj_list,informTime,it,time+informTime[node]);
            flag=1;
        }
        if(flag==0){
            minTime=max(minTime,time);
        }
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj_list(n);
        // int root;
        for(int i=0;i<n;i++){
            if(manager[i]==-1){
                // root=i;
                // adj_list[]
                
            }
            else{
                adj_list[manager[i]].push_back(i);
            }
        }
        // time=0;
        dfs(adj_list,informTime,headID,0);
        // vector<int> visit(n,0);
        // queue<int> q;
        // q.push(headID);
        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     cout<<node<<" "<<informTime[node]<<endl; 
        //     if(visit[node]==1)
        //         continue;
        //     visit[node]=1;
        //     for(auto i:adj_list[node]){
        //         if(visit[i]==0){
        //             q.push(i);
        //         }
        //     }
        //     time+=informTime[node];
        // }
        return minTime;
    }
};