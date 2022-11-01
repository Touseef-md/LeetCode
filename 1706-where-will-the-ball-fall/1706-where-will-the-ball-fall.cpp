int m,n;
int dfs(vector<vector<int>> & grid,int i,int j){
    // cout<<i<<"   "<<j<<endl;
    if((grid[i][j]==1&&j+1==n)||(grid[i][j]==-1&&j-1==-1)||(grid[i][j]==1&&grid[i][j+1]==-1)||(grid[i][j]==-1&&grid[i][j-1]==1))
        return -1;
    if(i==m-1){
        if(grid[i][j]==1)
            return j+1;
        return j-1;
    }
        // return 1;
    if(grid[i][j]==1)
        return dfs(grid,i+1,j+1);
    return dfs(grid,i+1,j-1);
    
}
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<int> result;
        for(int i=0;i<n;i++){
            int x=0;
            // dfs(grid,x,i);
            result.push_back(dfs(grid,x,i));
        }
        return result;
    }
};