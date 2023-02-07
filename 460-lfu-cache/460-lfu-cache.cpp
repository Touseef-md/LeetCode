class Node{
    public:
    Node* next=NULL;
    Node* prev=NULL;
    int key;
    int value;
    int freq;
    Node(){
        next=NULL;
        prev=NULL;
        key=-1;
        freq=0;
    }

};
class LFUCache {
public:

    int _capacity=0,lowfreq=1;
    unordered_map<int,Node*> keyNode;
    unordered_map<int,vector<Node*>> freqHead;
    void updatefreq(Node* root){
        if(root->next->next==NULL&&root->prev->prev==NULL){
            if(lowfreq==root->freq){
                lowfreq++;
            }
        }
    }
    void removeNode(Node* root){
        Node* temp=root;
        root->prev->next=root->next;
        root->next->prev=root->prev;
        int k=root->key;
        keyNode.erase(root->key);

        auto it=keyNode.find(k);
        delete temp;
        return;
    }
    void addNode(Node* root){
        int freq=root->freq;
        auto it=freqHead.find(freq);
        Node* head;
        if(it==freqHead.end()){
            head=new Node();
            Node* tail=new Node();
            head->next=tail;
            tail->prev=head;
            freqHead[freq]={head,tail};
        }
        else{
            head=freqHead[freq][0];
        }
        root->next=head->next;
        root->prev=head;
        head->next->prev=root;
        head->next=root;
        keyNode[root->key]=root;
        return;
    }
    LFUCache(int capacity) {
        _capacity=capacity;
    }
    
    int get(int key) {
        auto it=keyNode.find(key);
        if(it==keyNode.end()){
            return -1;
        }
        else{
            Node* node=it->second;
            Node* newNode=new Node();
            newNode->key=key;
            int value=node->value;
            newNode->value=node->value;
            newNode->freq=node->freq+1;
            this->addNode(newNode);
            this->updatefreq(node);
            this->removeNode(node);

            keyNode[key]=newNode;
            return value;
        }
    }
    
    void put(int key, int value) {
        auto it=keyNode.find(key);
        if(it==keyNode.end()){
            Node* newNode=new Node();
            newNode->value=value;
            newNode->key=key;
            newNode->freq=1;
            keyNode[key]=newNode;
            if(_capacity>0){
                this->addNode(newNode);
                _capacity--;
            }
            else{
                auto it1=freqHead.find(lowfreq);
                Node* tailNode=(it1->second)[1];
                this->removeNode(tailNode->prev);
                this->addNode(newNode);
            }
                lowfreq=1;

        }
        else{
            Node* node=it->second;
            Node* newNode=new Node();
            newNode->key=key;
            newNode->value=value;
            newNode->freq=node->freq+1;
            keyNode[key]=newNode;
            this->updatefreq(node);
            this->removeNode(node);
            this->addNode(newNode);
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */