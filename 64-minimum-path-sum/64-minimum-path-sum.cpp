class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int fun(vector<vector<int>>& grid,int i,int j){
        if(i>=m||j>=n)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==grid.size()-1&&j==grid[0].size()-1){
            return dp[i][j]=grid[i][j];
        }
        return dp[i][j]=grid[i][j]+min(fun(grid,i+1,j),fun(grid,i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.clear();
        dp.resize(m,vector<int>(n,-1));
        return fun(grid,0,0);
    }
};