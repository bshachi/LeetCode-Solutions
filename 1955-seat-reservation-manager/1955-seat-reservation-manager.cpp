class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        // cout<<"jsbdv\n";
        for (int i = 1; i <= n; i++) pq.push(i);
    }
    
    int reserve() {
        // cout<<pq.top()<<"res\n";
        int x = pq.top();
        pq.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        // cout<<seatNumber<<"unres\n";
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */