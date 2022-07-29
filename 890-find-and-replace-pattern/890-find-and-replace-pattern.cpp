class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int flag=0,n=words.size(),m=pattern.length();
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        vector<string> result;
        for(int i=0;i<n;i++){
            mp1.clear();
            mp2.clear();
            flag=0;
            for(int j=0;j<m;j++){
                auto it=mp1.find(pattern[j]);
                if(it!=mp1.end()){
                    if(it->second==words[i][j])
                        continue;
                    else{
                        flag=1;
                        break;
                    }
                }
                else{
                    auto it2=mp2.find(words[i][j]);
                    if(it2==mp2.end()){
                        mp1[pattern[j]]=words[i][j];
                        mp2[words[i][j]]=pattern[j];
                    }
                    else{
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};