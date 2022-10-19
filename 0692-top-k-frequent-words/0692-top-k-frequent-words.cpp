bool comp(pair<int,string>& a,pair<int,string> & b){
    if(b.first>a.first)
        return false;
    else if(b.first==a.first){
        if(b.second<=a.second)
            return false;
        return true;
    }
    return true;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        unordered_map<string,int> mp;
        for(auto i:words){
            mp[i]++;
        }
        for(auto i:mp){
            pq.push({i.second,i.first});
            // if(pq.size()==k+1){
            //     pq.pop();
            // }
        }
        vector<pair<int,string>> temp_result;
        while(!pq.empty()){
            temp_result.push_back(pq.top());
            pq.pop();
        }
        sort(temp_result.begin(),temp_result.end(),comp);
        vector<string> result;
        for(auto i:temp_result){
            if(result.size()==k)
                break;
            result.push_back(i.second);
        }
        return result;
    }
};