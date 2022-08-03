class MyCalendar {
public:
    // set<pair<int,int>> event;
    multimap<int,int> event;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=event.upper_bound(start);
        if(it==event.end()){
            event.insert({end,start});
            return true;
        }
        if(it->second>=end){
            event.insert({end,start});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */