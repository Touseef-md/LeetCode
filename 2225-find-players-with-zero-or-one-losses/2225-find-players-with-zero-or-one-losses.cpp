class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winner;
        unordered_map<int,int> loser;
        for(auto i:matches){
            winner[i[0]]++;
            loser[i[1]]++;
        }
        vector<vector<int>> result(2);
        for(auto it:winner){
            auto i=loser.find(it.first);
            if(i==loser.end()){
                result[0].push_back(it.first);
            }
        }
        for(auto it:loser){
            if(it.second==1){
                result[1].push_back(it.first);
            }
        }
        sort(result[0].begin(),result[0].end());
        sort(result[1].begin(),result[1].end());
        return result;
    }
};