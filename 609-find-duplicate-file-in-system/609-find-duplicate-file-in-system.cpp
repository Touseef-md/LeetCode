class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        for(auto i:paths){
            string st="",a="",st2="";
            i+=' ';
            int flag=0,flag2=0;
            for(auto j:i){
                if(j==' '){
                    if(flag==0){
                        a=st;
                        st="";
                        flag=1;
                        continue;
                    }
                    else{
                     mp[st2].push_back(a+'/'+st);
                    st="";
                        st2="";
                        continue;
                    }
                }
                if(j=='('){
                    flag2=1;
                    continue;
                }
                if(j==')'){
                    flag2=0;
                    continue;
                }
                if(flag2==1){
                    st2+=j;
                }
                else
                    st+=j;
            }
        }
        vector<vector<string>> result;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second.size()>1)
            result.push_back(it->second);
        }
        return result;
        // return {{}};
    }
};