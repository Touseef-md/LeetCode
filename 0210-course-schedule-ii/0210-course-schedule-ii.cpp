class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<int> indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int index;
        vector<int> result;
        while(!q.empty()){
            index=q.front();
            result.push_back(index);
            q.pop();
            for(auto neigh:adj_list[index]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if(result.size()!=numCourses){
            return {};
        }
        return result;
    }
};