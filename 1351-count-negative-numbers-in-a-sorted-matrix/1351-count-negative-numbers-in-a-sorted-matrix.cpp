class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int i=0,j=n-1,result=0;
        while(i<m&&j>=0){
            if(grid[i][j]<0){
                result+=m-i;
//                 if(j-1>=0){
//                     if(grid[i][j-1]<0){
//                         result+=m-i;    
//                     }
//                     else{
                        
//                     }
//                 }
                j--;
            }
            else{
                while(i<m&&grid[i][j]>=0){
                    i++;
                }
            }
        }
        return result;
    }
};