class Solution {
public:
void dfs(vector<vector<int>> &image,vector<vector<int>>&flag,int i,int j,int val,int &color){
    // cout<<i<<"  "<<j<<endl;
    if(flag[i][j]!=-1)
        return;
    flag[i][j]=1;
    if(image[i][j]!=val)
        return;
    if(image[i][j]==val)
    image[i][j]=color;
    if(i-1>=0)
        dfs(image,flag,i-1,j,val,color);
    if(i+1<image.size())
        dfs(image,flag,i+1,j,val,color);
    if(j-1>=0)
        dfs(image,flag,i,j-1,val,color);
    if(j+1<image[0].size())
        dfs(image,flag,i,j+1,val,color);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> flag(image.size(),vector<int> (image[0].size(),-1));
        dfs(image,flag,sr,sc,image[sr][sc],color);
        return image;
    }
};