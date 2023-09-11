class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> sizes(501);
        vector<vector<int>> result;
        for(int i=0;i<groupSizes.size();i++){
            sizes[groupSizes[i]].push_back(i);
        }
        
        for(int i=1;i<=500;i++){
            if(sizes[i].size()%i==0){
                // for(int j=0;j)
                int j=0;
                vector<int> temp;
                while(j<sizes[i].size()){
                    temp.push_back(sizes[i][j]);
                    if((j+1)%i==0){
                        result.push_back(temp);
                        temp.clear();
                    }
                    j++;
                }
            }
        }
        return result;
    }
};