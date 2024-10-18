class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it = mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
//         for(auto it=pq.begin();it!=pq.end();it++){
            
//         }
        vector<int> result;
        while(pq.size()>0){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
        // unordered_map<int,int> mp;
        // for(auto i:nums){
        //     mp[i]++;
        // }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // for(auto i:mp){
        //     pq.push({i.second,i.first});
        //     if(pq.size()>k)
        //         pq.pop();
        // }
        // vector<int> result;
        // while(pq.size()>0){
        //     result.push_back(pq.top().second);
        //     pq.pop();
        // }
        // sort(result.begin(),result.end());
        // return result;
    }
};