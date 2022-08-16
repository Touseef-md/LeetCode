class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        unordered_map<char,char> subtract;
        subtract['V']='I';
        subtract['X']='I';
        subtract['L']='X';
        subtract['C']='X';
        subtract['D']='C';
        subtract['M']='C';
        if(s.length()==1)
            return mp[s[0]];
        int value=0,i=0;
        for(i=0;i<s.length()-1;i++){
            auto it=subtract.find(s[i+1]);
            if(it!=subtract.end()&&it->second==s[i]){
                value-=mp[s[i]];
            }
            else{
                value+=mp[s[i]];
            }
            // if(it==subtract.end()){
            //     value+=mp[s[i]];
            // }
            // else{
            //     value-=mp[s[i]];
            // }
        }
        value+=mp[s[i]];
        return value;
    }
};