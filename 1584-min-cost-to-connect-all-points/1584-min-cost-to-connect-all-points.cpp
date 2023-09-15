class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int dist;
        vector<vector<pair<int,int>>> adj_list(n);
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(i!=j){
                    dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    adj_list[i].push_back({j,dist});
                    adj_list[j].push_back({i,dist});
                }
            }
        }
        vector<int> visit(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // int dist;
        int ver;
        pq.push({0,0});
        // visit[0]=;
        int result=0;
        while(!pq.empty()){
            dist=pq.top().first;
            ver=pq.top().second;
            pq.pop();
            
            if(visit[ver]==1){
                continue;
            }
            result+=dist;
            visit[ver]=1;
            for(auto neigh:adj_list[ver]){
                if(visit[neigh.first]==0){
                    pq.push({neigh.second,neigh.first});
                }
            }
        }
        return result;
        
    }
};