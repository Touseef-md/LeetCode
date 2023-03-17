class Trie {
public:
    char ch;
    bool isWord;
    unordered_map<int,Trie*> arr;
    Trie() {
        isWord=false;
        // ch;
        // for(int i=0;i<26;i++){
        //     arr[i]=NULL;
        // }
    }
    
    void insert(string word) {
        int i=0,n=word.size();
        Trie* node=this;
        Trie* temp;
        while(i<n){
            if(node->arr[word[i]-'a']==NULL){
                temp=new Trie();
                node->arr[word[i]-'a']=temp;
                node->ch=word[i]; 
            }
            else{
                temp=node->arr[word[i]-'a'];
            }
            node=temp;
            i++;
        }
        node->isWord=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        int i=0,n=word.size();
        while(i<n){
            if(node->arr[word[i]-'a']==NULL)
                return false;
            node=node->arr[word[i]-'a'];
            i++;
        }
        if(node->isWord)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        int i=0,n=prefix.size();
        while(i<n){
            if(i==0&&node->arr[prefix[i]-'a']==NULL){
                return false;
            }
            if(node->arr[prefix[i]-'a']==NULL)
                return false;
            node=node->arr[prefix[i]-'a'];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */