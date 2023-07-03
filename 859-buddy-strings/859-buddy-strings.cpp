class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int count=0,i=0,n=s.size();
        if(s.size()!=goal.size())
            return false;
        int one=-1,two=-1;
        while(i<n){
            if(s[i]!=goal[i]){
                if(one==-1){
                    one=i;
                }
                else{
                    two=i;
                }
                count++;
            }
            i++;
        }
        // if()
        if(count>2)
            return false;
        if(count==2){
            swap(s[one],s[two]);
            return s==goal;
        }
        else if(count==1){
            return false;
        }
        else{
            unordered_map<int,int> mp;
            for(i=0;i<n;i++){
                mp[s[i]-'a']++;
                    if(mp[s[i]-'a']>=2){
                        return true;
                    }
            }
            return false;
        }
    }
};