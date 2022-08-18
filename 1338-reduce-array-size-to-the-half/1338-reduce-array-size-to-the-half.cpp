bool comp(pair<int,int> &a,pair<int,int>& b){
    if(a.second>b.second)
        return true;
    return false;
}
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<pair<int,int>> v;
        for(auto i:arr)
            mp[i]++;
        for(auto i:mp){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),comp);
        int n=arr.size(),count=0;
        for(int i=0;i<v.size();i++){
            count+=v[i].second;
            if((n-count)<=(n+1)/2)
                return i+1;
        }
        return -1;
    }
};