class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj_list(numCourses);
        
        for(auto edge:prerequisites){
            indegree[edge[1]]++;
            adj_list[edge[0]].push_back(edge[1]);
        }
        // priority_queue
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int ver=q.front();
            q.pop();
            count++;
            for(auto neigh:adj_list[ver]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if(count!=numCourses)
            return false;
        return true;
    }
};