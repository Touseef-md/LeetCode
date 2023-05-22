int m;
class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,queue<pair<int,int>>& q){
        q.push({i,j});
        grid[i][j]=2;
        if(i+1<m&&grid[i+1][j]==1){
            dfs(grid,i+1,j,q);
        }
        if(i-1>=0&&grid[i-1][j]==1){
            dfs(grid,i-1,j,q);
        }
        if(j+1<m&&grid[i][j+1]==1){
            dfs(grid,i,j+1,q);
        }
        if(j-1>=0&&grid[i][j-1]==1){
            dfs(grid,i,j-1,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int flag=0;
        queue<pair<int,int>> q;
        m=grid.size();
        // q.clear();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,q);
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        //   for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         cout<<grid[i][j]<<" ";
        //         // if(grid[i][j]==1){
        //         //     dfs(grid,i,j);
        //         //     flag=1;
        //         //     break;
        //         // }
        //     }
        //       cout<<endl;
        //     // if(flag==1)
        //     //     break;
        // }
        
        //DOING THE BFS TO FIND THE SHORTEST PATH BETWEEN THE TWO ISLANDS
        int x,y,count=0;
        q.push({-1,-1});
        vector<vector<int>> visited(m,vector<int>(m,-1));
        // cout<<q.size()<<endl;
        while(q.size()>1){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            if(x==-1&&y==-1){
                count++;
                q.push({-1,-1});
                continue;
            }
            if(grid[x][y]==1){
                return count-1;
            }
            grid[x][y]=2;
        if(x+1<m&&grid[x+1][y]!=2&&visited[x+1][y]!=0){
            q.push({x+1,y});
            visited[x+1][y]=0;
            // dfs(grid,i+1,j);
        }
        if(x-1>=0&&grid[x-1][y]!=2&&visited[x-1][y]!=0){
            q.push({x-1,y});
            visited[x-1][y]=0;
            // dfs(grid,i-1,j);
        }
        if(y+1<m&&grid[x][y+1]!=2&&visited[x][y+1]!=0){
            q.push({x,y+1});
            visited[x][y+1]=0;
            // dfs(grid,i,j+1);
        }
        if(y-1>=0&&grid[x][y-1]!=2&&visited[x][y-1]!=0){
            // dfs(grid,i,j-1);
            q.push({x,y-1});
            visited[x][y-1]=0;
        }
        }
        return count-1;
    }
};