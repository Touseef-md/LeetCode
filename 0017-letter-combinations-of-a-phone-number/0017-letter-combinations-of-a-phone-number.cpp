class Solution {
public:
    void allComb(string &digits,vector<vector<char>>& encode,vector<string>& result,int i,string &ans){
        if(i>=digits.size()){
            result.push_back(ans);      
            return;
        }
        int digit=digits[i]-'0';
        for(int j=0;j<encode[digit].size();j++){
            ans+=encode[digit][j];
            allComb(digits,encode,result,i+1,ans);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }
     vector<vector<char>> encode={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<string> result;
        string ans="";
        allComb(digits,encode,result,0,ans);
        return result;
    }
};