class StockSpanner {
public:
    stack<pair<int,int>> st;
    int count=0;
    StockSpanner() {
        stack<int> st;
        count=0;
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        }
        count=1;
        while(!st.empty()&&st.top().first<=price){
            count+=st.top().second;
            st.pop();
        }
        st.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */