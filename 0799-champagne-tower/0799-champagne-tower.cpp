class Solution {
public:
//     vector<vector<int>> dp(query_row+1,vector<int>(query_row+1,-));
//     double Tower(int row,int col){
//         if(row==1&&col==1){
//             dp[row][col]=1;
//             return 0;
//         }
//         if(row==1){
//             return 0;
//         }
//         double rightOverflow=Tower(row-1,col);
//         double leftOverflow=Tower(row-1,col-1);
//         double rem=1;
//         if(dp[row-1][col]<dp[row-1][col-1]){
//             rem-=rightOverflow;
//         }
//         else if(dp[row-1][col]==dp[row-1][col-1])
//         else{
            
//         }
//     }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>str(query_row+5,vector<double>(query_row+5,0));
        str[0][0]=poured;
        for(int i=0;i<=query_row;i++){
            // if(i==0)continue;
            for(int j=0;j<=i;j++){
                if(str[i][j]>1){
                    str[i+1][j]+=(str[i][j]-1)/2.0;
                    str[i+1][j+1]+=(str[i][j]-1)/2.0;
                }
                // str[i][j]=1;
            }
        }
        if(str[query_row][query_glass]>1){
            return 1;
        }
        return str[query_row][query_glass];
    }
};