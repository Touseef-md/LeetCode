class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<char,int> universal_freq;
        unordered_map<char,int> word_freq;
        vector<string> answer;
        for(auto i:words2){
            word_freq.clear();
            for(int j=0;j<i.length();j++){
                word_freq[i[j]]++;
            }
            for(auto it=word_freq.begin();it!=word_freq.end();it++){
                auto  i=universal_freq.find(it->first);
                if(i==universal_freq.end()){
                    universal_freq[it->first]=it->second;
                }
                else{
                    universal_freq[it->first]=max(universal_freq[it->first],it->second);
                }
            }
        }
        // for(auto it:universal_freq)
        //     cout<<it.first<<" "<<it.second<<endl;
        int flag=0;
        for(auto i:words1){
            word_freq.clear();
            flag=0;
            for(int j=0;j<i.length();j++){
                word_freq[i[j]]++;
            }
            for(auto it=universal_freq.begin();it!=universal_freq.end();it++){
                auto it2=word_freq.find(it->first);
                if(it2==word_freq.end()){
                    // cout<<i<<"NOt Present"<<endl;
                    flag=1;
                    break;
                }
                else if(it->second>word_freq[it->first]){
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                answer.push_back(i);
        }
        return answer;
    }
};