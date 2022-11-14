class Solution {
public:
    // vector<pair<int,int>> root;
    vector<int> root;
    vector<int> rank;
    int findrootX(int x){
        if(root[x]==x)
            return x;
        return root[x]=findrootX(root[x]);
    }
    void unionn(int x,int y){
        int rootX=findrootX(x);
        int rootY=findrootX(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                root[rootY]=rootX;
            }
            else if(rank[rootX]<rank[rootY]){
                root[rootX]=rootY;
            }
            else{
                root[rootY]=rootX;
                rank[rootX]+=1;
            }
        }
    }
    bool isConnected(int x,int y){
        return findrootX(x)==findrootX(y);
    }
    int removeStones(vector<vector<int>>& stones) {
        root.clear();
        rank.clear();
        root.resize(stones.size());
        rank.resize(stones.size(),0);
        for(int i=0;i<stones.size();i++){
            // root[i]={stones[i][0],stones[i][1]};
            root[i]=i;
        }
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<stones.size();j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    unionn(i,j);
                }
            }
        }
        int result=0,size=0;
        vector<int> connectedComponent(stones.size(),0);
        for(int i=0;i<stones.size();i++){
            if(i==root[i])
                result++;
        }
        return stones.size()-result;
        // for(int i=0;i<stones.size();i++){
        //     connectedComponent[root[i]]++;
        // }
        // return *max_element(connectedComponent.begin(),connectedComponent.end())-1;
        
    }
};