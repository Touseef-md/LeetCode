class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j+1<n&&i+j+1<m){
                    if(matrix[j][i+j]!=matrix[j+1][i+j+1])
                        return false;
                }
            }
        }
        for(int i=n-1;i>0;i--){
            for(int j=0;j<m;j++){
                if(i+j+1<n&&j+1<m){
                    if(matrix[i+j][j]!=matrix[i+j+1][j+1])
                        return false;
                }
            }
        }
        return true;
    }
};