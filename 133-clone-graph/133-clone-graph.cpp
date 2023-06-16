/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<int> visit;
    Node* temp;
    int countNodes=0;
    vector<vector<int>> adjMatrix;
    void dfs(Node* node){
        if(node==NULL||visit[node->val]==1)
            return ;
        countNodes++;
        visit[node->val]=1;
        for(auto i:node->neighbors){
            adjMatrix[node->val][i->val]=1;
            dfs(i);
        }
    }
    Node* cloneGraph(Node* node) {
        visit.clear();
        visit.resize(101,0);
        adjMatrix.clear();
        adjMatrix.resize(101,vector<int>(101,0));
        countNodes=0;
        dfs(node);
        if(countNodes==1)
            return new Node(node->val);
        unordered_map<int,Node*> mp;
        Node* newNode1;
        Node* newNode2;
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                if(adjMatrix[i][j]==1){
                    auto it=mp.find(i);
                    if(it==mp.end()){
                        newNode1=new Node(i);
                        auto it2=mp.find(j);
                        if(it2==mp.end()){
                            newNode2=new Node(j);
                            mp[j]=newNode2;
                        }
                        else{
                            newNode2=it->second;
                        }
                        newNode1->neighbors.push_back(newNode2);
                        mp[i]=newNode1;
                    }
                    else{
                        auto it2=mp.find(j);
                        if(it2==mp.end()){
                            newNode2=new Node(j);
                            mp[j]=newNode2;
                        }
                        else{
                            newNode2=it2->second;
                        }
                        it->second->neighbors.push_back(newNode2);
                    }
                }
            }
        }
        return mp[1];
    }
};