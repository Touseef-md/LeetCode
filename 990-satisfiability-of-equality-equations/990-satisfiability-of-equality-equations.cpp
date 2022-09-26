class Solution {
public:
    vector<char> root;
    vector<int>rank;
    void unionn(char x,char y){
        char rootX=find(x);
        char rootY=find(y);
        if(rootX!=rootY){
            if(rank[rootX-'a']>rank[rootY-'a']){
                root[rootY-'a']=rootX;
            }
            else if(rank[rootX-'a']<rank[rootY-'a'])
                root[rootX-'a']=rootY;
            else{
                root[rootY-'a']=rootX;
                rank[rootX-'a']+=1;
            }
        }
    }
    char find(char a){
        if(root[a-'a']==a)
            return a;
        return root[a-'a']=find(root[a-'a']);
    }
    bool equationsPossible(vector<string>& equations) {
        root.clear();
        rank.clear();
        root.resize(26);
        rank.resize(26,0);
        char z='a';
        for(int i=0;i<26;i++){
            root[i]=z;
            z++;
            // cout<<z<<endl;
        }
        for(auto i:equations){
            if(i[1]=='='){
                if(find(i[0])!=find(i[3])){
                    unionn(i[0],i[3]);
                }
            }
            else{
                if(find(i[0])==find(i[3]))
                    return false;
            }
        }
        for(auto i:equations){
            if(i[1]=='!'){
                if(find(i[0])==find(i[3]))
                    return false;
            }
        }
        return true;
    }
};