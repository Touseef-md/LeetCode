class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int> transformations;
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string st="";
        for(auto i:words){
            st="";
            for(auto j:i){
                st+=morse[j-'a'];
            }
            transformations[st]++;
        }
        return transformations.size();
    }
};