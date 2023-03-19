class Trie{
    public:
    unordered_map<int,Trie*> mp;
    // vector<pair<int,Trie*>> mp;
    bool isWord;
    Trie(){
        // for(int i=0;i<26;i++){
        //     mp[i]=NULL;
        // }
        isWord=false;
    }
};
class WordDictionary {
public:
    // unordered_map<int,WordDictionary*> mp;
    Trie* head;
    WordDictionary() {
        head=new Trie();
        // head->ch='!';
    }
    
    void addWord(string word) {
        // WordDictionary* node=this;
        Trie* node=head;
        int i=0,n=word.size();
        while(i<n){
            if(node->mp[word[i]-'a']==NULL){
                Trie* temp=new Trie();
                // temp->ch=word[i];
                node->mp[word[i]-'a']=temp;
                node=temp;
            }
            else{
                node=node->mp[word[i]-'a'];
            }
            i++;
        }
        node->isWord=true;
    }
    bool searchHelper(string& word,int k=0,Trie* head2=NULL){
        int i=k,n=word.size();
        Trie* node=(head2==NULL)?head:head2;
        // cout<<"HEad node is "<<node->ch<<endl;
        while(i<n){
            if(node->mp[word[i]-'a']==NULL){
                if(word[i]=='.'){
                    // cout<<"i is "<<i<<" "<<endl;
                    bool temp_ans=false;
                    if(node->mp.size()>0)
                    for(auto it=(node->mp.begin());it!=(node->mp.end());it++){
                        if(it->first>=0&&it->first<26&&it->second!=NULL){
                            // cout<<"FIrst is "<<it->first<<endl;
                            temp_ans|=searchHelper(word,i+1,it->second);
                            if(temp_ans)
                                return true;
                        }
                    }
                    return false;
                }
                else{
                    return false;
                }
            }
            else{
                node=node->mp[word[i]-'a'];
            }
            i++;
        }
        if(node->isWord)
            return true;
        return false;
    }
    bool search(string word,int k=0,Trie* head2=NULL) {
        return searchHelper(word,0,head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */