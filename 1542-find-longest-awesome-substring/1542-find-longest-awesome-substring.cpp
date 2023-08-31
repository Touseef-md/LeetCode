class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        // vector<int> freq(10,0);
        int freq=0,result=0;
        for(int i=0;i<n;i++){
            freq^=(1<<(s[i]-'0'));
            auto it=mp.find(freq);
            if(it==mp.end()){
                mp[freq]=i;
            }
            else{
                result=max(result,i-it->second);
            }
            int temp=freq;
            for(int j=0;j<=9;j++){
                auto it1=mp.find(temp^(1<<j));
                if(it1!=mp.end()){
                    result=max(result,i-it1->second);
                }
            }
            // freq[s[i]-'0']^=[freq[s[i]-'0']
        }
        return result;
    }
};