class MyStack {
public:
    queue<int> q1;
    // queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int s=q1.size();
        int temp;
        while(s-->1){
            temp=q1.front();
            q1.pop();
            q1.push(temp);
        }
        temp=q1.front();
        q1.pop();
        return temp;
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // temp=q2.front();
        // q2.pop();
        // return temp;
    }
    
    int top() {
        int s=q1.size();
        int temp;
        while(s-->1){
            temp=q1.front();
            q1.pop();
            q1.push(temp);
        }
        temp=q1.front();
        q1.pop();
        q1.push(temp);
        return temp;
    }
    
    bool empty() {
        if(q1.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */