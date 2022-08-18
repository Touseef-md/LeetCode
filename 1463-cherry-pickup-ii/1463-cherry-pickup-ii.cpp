class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int> dir={-1,0,1};
    int maxCherry(vector<vector<int>>& grid,int i,int j,int k){
        if(i>=grid.size()||j<0||j>=grid[0].size()||k<0||k>=grid[0].size())
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        int maxi=-1;
        for(auto it1:dir){
            for(auto it2:dir){
                if(j!=k)
                    maxi=max(maxi,grid[i][j]+grid[i][k]+maxCherry(grid,i+1,j+it1,k+it2));
                else
                    maxi=max(maxi,grid[i][j]+maxCherry(grid,i+1,j+it1,k+it2));
            }
        }
        return dp[i][j][k]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        dp.clear();
        dp.resize(grid.size(),vector<vector<int>> (grid[0].size(),vector<int>(grid[0].size(),-1)));
        return maxCherry(grid,0,0,grid[0].size()-1);
    }
};