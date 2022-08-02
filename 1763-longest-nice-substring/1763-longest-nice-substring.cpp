class Solution {
public:
    string longestNiceSubstring(string s) {
        int i,len=0,flag=0;
        string st="";
        unordered_map<char,int> mp;
        for( i=0;i<s.length();i++){
            // cout<<i<<endl;
            mp.clear();
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
            
            // cout<<mp.size()<<endl;
            flag=0;
            for(auto it=mp.begin();it!=mp.end();it++){
                auto it1=mp.find(char(it->first+32));
                auto it2=mp.find(char(it->first-32));
                // cout<<i<<endl;
                if(it1==mp.end()&&it2==mp.end()){
                    flag=1;
                    // cout<<i<<"  "<<j<<endl;
                    break;
                }
            }
        if(flag==0){
            if((j-i+1)>len){
                // cout<<i<<" "<<j<<endl;
                st=s.substr(i,j-i+1);
                len=j-i+1;
            }
        }
        }
        }
        return st;
    }
};