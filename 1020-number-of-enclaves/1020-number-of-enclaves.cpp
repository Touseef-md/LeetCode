class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>&grid,int i,int j){
        grid[i][j]=0;
        if(i+1<m&&grid[i+1][j]==1){
            dfs(grid,i+1,j);
        }
        if(i-1>=0&&grid[i-1][j]==1){
            dfs(grid,i-1,j);
        }
        if(j+1<n&&grid[i][j+1]==1){
            dfs(grid,i,j+1);
        }
        if(j-1>=0&&grid[i][j-1]==1){
            dfs(grid,i,j-1);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            if(i==0||i==m-1){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        dfs(grid,i,j);
                    }
                }
            }
            else{
                if(grid[i][0]==1){
                    dfs(grid,i,0);
                }
                if(grid[i][n-1]==1){
                    dfs(grid,i,n-1);
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
        
    }
};