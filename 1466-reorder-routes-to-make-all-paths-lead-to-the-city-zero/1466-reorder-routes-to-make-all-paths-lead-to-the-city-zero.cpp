class Solution {
public:
    vector<vector<bool>> reach;
    vector<vector<int>> adj;
    vector<vector<int>> revadj;
    
    int count=0;
    // void dfs1(int i){
    //     for(auto it:adj[i]){
    //         count++;
    //         reach[it][0]=true;
    //         dfs1(it);
    //     }
    // }
    // void dfs(int i){
    //     for(auto it:adj[i]){
    //         if(!reach[it][0])
    //     }
    // }
    int minReorder(int n, vector<vector<int>>& connections) {
        reach.clear();
        adj.clear();
        revadj.clear();
        adj.resize(n);
        revadj.resize(n);
        count=0;
        reach.resize(n,vector<bool> (1,false));
        reach[0][0]=true; priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            revadj[it[1]].push_back(it[0]);
            if(it[1]==0){
                reach[it[0]][0]=true;
                pq.push({0,it[0]});
            }
        }
        pq.push({0,0});
        while(!pq.empty()){
            int r=pq.top().first;
            int i=pq.top().second;
            pq.pop();
            for(auto it:adj[i]){
                if(!reach[it][0]){
                    count++;
                    reach[it][0]=true;
                    pq.push({0,it});
                }
            }
            for(auto it:revadj[i]){
                if(!reach[it][0]){
                    reach[it][0]=true;
                    pq.push({0,it});
                }
            }
        }
        // dfs(0);
        // for(int i=0;i<n;i++){
        //     for(auto it:connections){
        //         if(it[0]==0){
        //             if(!reach[it[1]][it[0]]){
        //                 count++;
        //                 reach[it[1]][it[0]]=true;
        //             }
        //         }
        //         else if(it[1]==0){
        //             if(!reach[it[0]][0]){
        //                 // count++;
        //                 reach[it[0]][0]=true;
        //             }
        //         }
        //         else{
        //             if(reach[it[0]][0]){
        //                 if(!reach[it[1]][0]){
        //                     count++;
        //                     reach[it[1]][0]=true;
        //                 }
        //             }
        //             else if(reach[it[1]][0])
        //                 reach[it[0]][0]=true;
        //         }
        //     }
        // }
        return count;
    }
};