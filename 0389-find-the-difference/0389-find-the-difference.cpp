class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26);
        for(auto ch:t){
            freq[ch-'a']++;
        }
        for(auto ch:s){
            freq[ch-'a']--;
        }
        int count=0;
        char ch;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                ch=char('a'+i);
            }
            count+=freq[i];
        }
        if(count==1){
            return ch;
        }
        return ch;
    }
};