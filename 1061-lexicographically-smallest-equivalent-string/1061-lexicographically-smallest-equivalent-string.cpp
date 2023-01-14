vector<vector<int>> lexi(26);
vector<int> visit1;
vector<int> visit2;
vector<int> ansChar;
int mini=27;
void dfs1(int i){
    visit1[i]=1;
    mini=min(mini,i);
    for(auto j:lexi[i]){
        if(visit1[j]==0){
            dfs1(j);
        }
    }
}
void dfs2(int i){
    visit2[i]=1;
    ansChar[i]=mini;
    for(auto j:lexi[i]){
        if(visit2[j]==0){
            dfs2(j);
        }
    }
}
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        lexi.clear();
        lexi.resize(26);
        ansChar.clear();
        ansChar.resize(26);
        visit1.clear();
        visit2.clear();
        visit2.resize(26,0);
        visit1.resize(26,0);
        for(int i=0;i<s1.length();i++){
            lexi[s1[i]-'a'].push_back(s2[i]-'a');
            lexi[s2[i]-'a'].push_back(s1[i]-'a');
        }

        for(int i=0;i<26;i++){
            mini=27;
            if(visit1[i]==0){
                dfs1(i);
                ansChar[i]=mini;
                dfs2(i);
            }
        }
        // for(int i=0;i<26;i++){
        //     cout<<char('a'+i)<<" ";
        //     for(int j=0;j<26;j++){
        //         cout<<lexi[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // }
        string st="";
        for(int i=0;i<baseStr.length();i++){
            st+=char(ansChar[baseStr[i]-'a']+'a');
            // cout<<st<<endl;
        }
        return st;
    }
};