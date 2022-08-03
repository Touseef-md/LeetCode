class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // METHOD 1: Using MAX-HEAP
        // int n=matrix.size();
        // priority_queue<int> pq;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(pq.size()<k+1){
        //             pq.push(matrix[i][j]);
        //         }
        //         else{
        //             if(pq.top()>matrix[i][j]){
        //                 pq.pop();
        //                 pq.push(matrix[i][j]);
        //             }
        //         }
        //     }
        // }
        // if(pq.size()>k)
        //     pq.pop();
        // return pq.top();
        
        
        //METHOD 2:Using MIN-HEAP
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int count=0,m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<min(k,m);i++){
            pq.push({matrix[i][0],i,0});
        }
        auto it=pq.top();
        while(count<k-1){
            if(!pq.empty()){
            it=pq.top();
                pq.pop();
            }           
            if(it[2]+1<n){
                pq.push({matrix[it[1]][it[2]+1],it[1],it[2]+1});
            }
            count++;
        }
        if(!pq.empty())return pq.top()[0];
        return 0;
    }
};