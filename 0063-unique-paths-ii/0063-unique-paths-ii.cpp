class Solution {
public:
    int sol(vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp,int i,int j){
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        // cout<<"Start "<<i<<"  "<<j<<endl;
        if(i>m||j>n|| obstacleGrid[i-1][j-1]==1){
            // cout<<"0 return "<<i<<"  "<<j<<endl;
            return 0;
        }
        if(i==m&&j==n){
            return 1;
        }
        // cout<<i<<"  "<<j<<endl;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=sol(obstacleGrid,dp,i+1,j)+sol(obstacleGrid,dp,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        dp[m][n]=1;
        // return 0;
        return sol(obstacleGrid,dp,1,1);
        // return dp[1][1];
    }
};