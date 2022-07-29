class Solution {
public:
    int funct(string& s,int i,int j,int& k){
        if(i>j)
            return 0;
        // if(i==j)
        //     return 1;
        vector<int> v(26);
        unordered_map<char,int> mp;
        for(int l=i;l<=j;l++)
            mp[s[l]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
            if((it->second)<k)
                v[(it->first)-'a']=1;
        int answer=0,flag=0,temp=i;
        for(int l=i;l<=j;l++){
            if(v[s[l]-'a']==0){
                // cout<<s[l]<<" "<<v[s[i]-'a']<<" FISRT  "<<l<<endl;
                // l++;
                continue;
            }
            else{
                // cout<<l<<endl;
                flag=1;
                answer=max(answer,funct(s,temp,l-1,k));
                temp=l+1;
            }
        }
        if(flag==0){
            // cout<<"FALG 0  "<<i<<" "<<j<<endl;
            return j-i+1;
        }
        answer=max(answer,funct(s,temp,j,k));
        return answer;
    }
    int longestSubstring(string s, int k) {
        return funct(s,0,s.length()-1,k);
//         vector<int> v(26);
//         unordered_map<char,int> mp;
//         for(auto i:s){
//             mp[i]++;
//         }
//         for(auto it=mp.begin();it!=mp.end();it++){
//             if(it->second<k){
                
//             // cout<<"CHECK 1"<<" "<<it->first<<endl;
//                 v[(it->first)-'a']=1;
//             }
//         }
//         // cout<<"CHECK 2"<<endl;
//         int answer=-1,count=0;
//         for(int i=0;i<s.length();i++){
//             if(v[s[i]-'a']==0){
//                 count++;
//             }
//             else{
//                 answer=max(answer,count);
//                 count=0;
//             }
//         }
//         answer=max(answer,count);
//         return answer;
    }
};