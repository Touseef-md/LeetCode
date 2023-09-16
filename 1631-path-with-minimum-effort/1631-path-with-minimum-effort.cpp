class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int count=0;
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> tempMatrix(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tempMatrix[i][j]=count;
                count++;
            }
        }
        
        
        vector<vector<pair<int,int>>> adj_list(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0)
                    adj_list[tempMatrix[i][j]].push_back({abs(heights[i][j]-heights[i-1][j]),tempMatrix[i-1][j]});
            if(i+1<m){
                 adj_list[tempMatrix[i][j]].push_back({abs(heights[i][j]-heights[i+1][j]),tempMatrix[i+1][j]});
            }
                if(j-1>=0){
                    adj_list[tempMatrix[i][j]].push_back({abs(heights[i][j]-heights[i][j-1]),tempMatrix[i][j-1]});
                }
                if(j+1<n){
                    adj_list[tempMatrix[i][j]].push_back({abs(heights[i][j]-heights[i][j+1]),tempMatrix[i][j+1]});
                }
            }
        }
        //DIJKSTRA'S ALgorithm
        // vector<int> 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> cost(m*n,INT_MAX);
        vector<int> visit(m*n,0);
        cost[0]=0;
        pq.push({0,0});
        int costTillNow;
        int ver;
        while(!pq.empty()){
            costTillNow=pq.top().first;
            ver=pq.top().second;
            pq.pop();
            // cout<<" This is the version 1      "<<ver<<endl;
            if(costTillNow!=cost[ver]){
                continue;
            }
            visit[ver]=1;
            // cout<<"THis is the vertex"<<ver<<endl;
            for(auto neigh:adj_list[ver]){
                if(visit[neigh.second]!=1&&max(costTillNow,neigh.first)<cost[neigh.second]){
                    // cout<<"PUSHING this "<<neigh.second<<endl;
                    cost[neigh.second]=max(costTillNow,neigh.first);
                    pq.push({cost[neigh.second],neigh.second});
                }
            }
        }
        return cost[m*n-1];
    }
};