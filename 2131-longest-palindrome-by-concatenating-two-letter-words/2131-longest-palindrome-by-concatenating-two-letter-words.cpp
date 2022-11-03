int Palindrome(string& a){
    int i=0,j=a.length()-1;
    while(i<=j){
        if(a[i]!=a[j])
            return 0;
        i++;j--;
    }
    return 1;
}
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,pair<int,int>> mp;
        int palin=0,count=0,one_freq_p=0;
        for(auto i:words){
            palin=Palindrome(i);
            mp[i].first=palin;
            mp[i].second+=1;
        }
        string st="";
        for(auto it:mp){
            if(it.second.first!=1){
                st="";
                for(int i=it.first.length()-1;i>=0;i--)
                    st+=it.first[i];
                auto it2=mp.find(st);
                if(it2!=mp.end()){
                    // cout<<"INside if "<<endl;
                    int mini=min(it.second.second,it2->second.second);
                    count+=2*mini;
                }
            }
            else{
                if(it.second.second%2!=0){
                    one_freq_p=1;
                }
                if(it.second.second%2==0){
                    count+=2*it.second.second;
                }
                // if(it.second.second>1){
                //     count+=2*
                // }
            }
        }
        // cout<<"Count "<<count<<endl;
        int maxi=count;
        for(auto it:mp){
            if(it.second.first==1&&it.second.second%2!=0){
                count+=(it.second.second-1)*2;
                // if(one_freq_p==1)
                    // x+2;
                // maxi=max(maxi,x);
            }
        }
        if(one_freq_p)
            count+=2;
        return count;
        return 0;
    }
};