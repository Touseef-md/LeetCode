class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        for(int i =0 ; i<allowed.length(); i++ ){
            mp[allowed[i]]++;
        }
        int flag=0, count =0;
        for(int i=0;i< words.size();i++){
            flag =0;
            for(int j=0;j< words[i].size() ;j++){
                if(mp[words[i][j]]<=0){
                    flag =1;
                    break;
                }
            }
            if(flag ==0){
                count++;
            }
        }
        return count;
    }
};