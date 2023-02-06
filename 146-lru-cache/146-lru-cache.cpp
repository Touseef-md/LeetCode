class Node{
    public:
    int val;
    int key;
    Node* next=NULL;
    Node* prev=NULL;
};
class LRUCache {
public:
    int cap=0;
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
    }
    void remove(Node* root){
        Node* temp=root;
        root->prev->next=root->next;
        root->next->prev=root->prev;
        // cout<<"middle"<<endl;
        // free(temp);
        delete temp;
        return;
    }
    Node* add(int key,int value){
        Node* newNode=new Node();
        newNode->val=value;
        newNode->key=key;
        newNode->prev=head;
        newNode->next=head->next;
        head->next->prev=newNode;
        head->next=newNode;
        // mp[]
        return newNode;
    }
    int get(int key) {
        // cout<<"GET "<<key<<endl;
        auto it=mp.find(key);
        if(it==mp.end())
            return -1;
        Node* node=it->second;
        int val=node->val;
        // cout<<"Beforw remove"<<endl;
        // mp.erase(node->key);
        this->remove(node);
        Node* newNode=this->add(key,val);
        // cout<<"After remove"<<endl;
        mp[key]=newNode;
        return val;
    }
    
    void put(int key, int value) {
        // cout<<"PUT  "<<key<<"  "<<value<<endl;
        auto it=mp.find(key);
        if(it==mp.end()){
            if(cap>0){
                Node* newNode=this->add(key,value);
                cap--;
                mp[key]=newNode;
            }
            else{
                // cap++;
                Node* node=tail->prev;
                mp.erase(node->key);
                this->remove(tail->prev);

                Node* newNode=add(key,value);
                mp[key]=newNode;
            }
        }
        else{
            Node* node=it->second;
            this->remove(node);
            Node* newNode=this->add(key,value);
            mp[key]=newNode;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */