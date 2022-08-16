class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto i:s)
            mp[i]++;
        for(int i=0;i<s.length();i++){
            auto it=mp.find(s[i]);
            if(it->second==1)
                return i;
        }
        return -1;
    }
};