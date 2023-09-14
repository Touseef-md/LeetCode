class Solution {
public:
unordered_map<string,multiset<string>> mp; 
int n;
vector<string> path;   //storing the path on the go
void dfs(string node){
    while(!mp[node].empty()){
        auto it=mp[node].begin();
        string st=*it;
        mp[node].erase(it);
        dfs(st);
    }
    path.push_back(node);
}

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // vector<string> res; //storing the result

        for(auto it:tickets){
            mp[it[0]].insert(it[1]);
        }
        n=tickets.size();
        // path.push_back("JFK");
        dfs("JFK");
        reverse(path.begin(),path.end());
        return path;
    }
};