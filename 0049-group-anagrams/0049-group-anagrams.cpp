class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<pair<string,string>,int> mp;
        vector<vector<string>> result;
        map<char,int> freq;
        for(auto it:strs){
            freq.clear();
            for(auto i:it)
                freq[i]++;
            string f="";
            for(auto i:freq){
                f+=i.first;
                f+=to_string(i.second);
            }
            string st="";
            for(auto j:freq){
                st+=j.first;
            }
            auto iter=mp.find({st,f});
            if(iter==mp.end()){
                mp[{st,f}]=result.size();
                result.push_back({it});
            }
            else{
                result[mp[{st,f}]].push_back(it);
            }
        }
        return result;
    }
};