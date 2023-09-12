class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        // map<int,vector<int>> mp;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<26;i++){
            // mp[freq[i]].push_back(i);
            if(freq[i]!=0)
            pq.push({freq[i],i});
        }
        int f,chr,result=0;
        unordered_map<int,int> mark;
        while(!pq.empty()){
            f=pq.top().first;
            chr=pq.top().second;
            pq.pop();
            if(mark[f]==1){
                result++;
                if(f-1>0)
                pq.push({f-1,chr});
            }
            else{
                mark[f]=1;
            }
            
        }
        return result;
        
    }
};