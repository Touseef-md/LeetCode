class Solution {
public:
    int partitionString(string s) {
        unordered_map<int,int> mp;
        int x,count=0;
        for(int i=0;i<26;i++){
            mp[i]=0;
        }
        for(int i=0;i<s.length();i++){
            x=mp[s[i]-'a'];
            if(x==0){
                mp[s[i]-'a']++;
            }
            else{
                count++;
                for(int j=0;j<26;j++){
                    mp[j]=0;
                }
                mp[s[i]-'a']=1;
            }
        }
        return count+1;
    }
};