class MyCalendar {
public:
    vector<pair<int,int>> calender;
    MyCalendar() {}
    
    bool book(int start, int end) {
        for (auto event:calender) {
            if (event.first < start) {
                if (event.second > start) return false;
            }
            else if (event.first < end) return false;
        }

        calender.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */