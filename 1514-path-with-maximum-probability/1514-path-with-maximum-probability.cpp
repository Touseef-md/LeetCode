class Solution {
public:
    vector<int> visit;
    // double maxProb=0;
    // int mini=1e-5;
    // void solve(vector<vector<pair<int,double>>>& adj_list,int &start,int& end,int &n,int i,double prob){
    //     // cout<<i<<endl;
    //     if(i==end){
    //         // cout<<"  GSDFSD"<<endl;
    //         maxProb=max(maxProb,prob);
    //         return ;
    //     }
    //     if(prob<maxProb){
    //         return;
    //     }
    //     if(prob<=mini){
    //         return;
    //     }
    //     if(visit[i]==1)
    //         return ;
    //     visit[i]=1;
    //     double maxi=0;
    //     for(auto it:adj_list[i]){
    //         // cout<<typeid(it)<<endl;
    //         if(visit[it.first]==0){
    //             solve(adj_list,start,end,n,it.first,prob*it.second);
    //             // maxi=max(maxi,it.second*solve(adj_list,start,end,n,it.first));
    //         }
    //         // cout<<maxi<<"   FSDF"<<endl;
    //     }
    //     // cout<<i<<"  "<<maxi<<endl;
    //     visit[i]=0;
    //     return ;
    // }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj_list(n);
        for(int i=0;i<edges.size();i++){
            adj_list[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj_list[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        // visit.clear();
        // visit.resize(n,-1);
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        vector<double> dist(n,0);
        dist[start]=1;
        while(!pq.empty()){
            double cost=pq.top().first;
            int v=pq.top().second;
            cout<<v<<endl;
            cout<<cost<<endl;
            pq.pop();
            if(dist[v]!=cost){
                continue;
            }
            // visit[v]=1;
            for(auto it:adj_list[v]){
                if(cost*it.second>dist[it.first]){
                    dist[it.first]=cost*it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist[end];
        // maxProb=0;
        // visit.clear();
        // visit.resize(n,0);
        // solve(adj_list,start,end,n,start,1);
        // return maxProb;
        
        //DIJKSTRA's
        
        
    }
};