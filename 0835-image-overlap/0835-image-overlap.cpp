class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxOverlap=0;
        for(int k=-(n-1);k<=n-1;k++){
            for(int l=-(n-1);l<=n-1;l++){
                vector<vector<int>> matrix(n,vector<int>(n,0));
                for(int i=n-1;i>=0;i--){
                    for(int j=0;j<n;j++){
                        if(i-l>=0&&i-l<n&&j+k>=0&&j+k<n)
                            matrix[i-l][j+k]=img1[i][j];
                    }
                }
                int overlap=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(matrix[i][j]==1&&matrix[i][j]==img2[i][j])
                            overlap++;
                    }
                }
                // cout<<k<<"  "<<l<<"  "<<overlap<<endl;
                maxOverlap=max(maxOverlap,overlap);
            }
        }
        return maxOverlap;
    }
};