#include<bits/stdc++.h>

class Solution {
public:
    static bool comp(pair<int,int>& a, pair<int,int>& b){
    if(b.first>a.first){
        return false;
    }
    return true;
    }
    string reorganizeString(string s) {
        int n=s.size(),maxi=0;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        // queue<pair<int,int>> pq;
        vector<pair<int,int>> sortFreq;
        for(int i=0;i<26;i++){
            if(freq[i]>0)
                sortFreq.push_back({freq[i],i});
            // pq.push({freq[i],i});
        }
        // for(int i=0;i<sortFreq.size();i++){
        //     cout<<sortFreq[i][0]<<"  "<<sortFreq[i][1]<<endl;
        // }
        sort(sortFreq.begin(),sortFreq.end(),comp);
        vector<vector<int>> sortf;
        for(auto p:sortFreq){
            sortf.push_back({p.first,p.second});
        }
        if(sortFreq[0].first>ceil(n*1.0/2)) return "";
        n=s.size();
        vector<char> ans(n);
        int ptr=0;
        for(int i=0;i<n;i+=2){
            ans[i]=sortFreq[ptr].second+'a';
            sortFreq[ptr].first--;
            if(sortFreq[ptr].first==0) ptr++;
        }
        for(int i=1;i<n;i+=2){
            ans[i]=sortFreq[ptr].second+'a';
            sortFreq[ptr].first--;
            if(sortFreq[ptr].first==0) ptr++;
        }
        string f="";
        for(char c:ans){
            f+=c;
        }
        return f;
        
        
       
    }
};