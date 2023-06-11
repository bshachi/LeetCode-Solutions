class SnapshotArray {
public:
    int n, sid = 0;
    unordered_map<int, pair<vector<int>,vector<int>>> s;
    SnapshotArray(int length) {
        n = length;
    }
    
    void set(int index, int val) {
        if (!s[index].first.empty() && *(s[index].first.end() - 1) == sid) {
            *(s[index].second.end() - 1) = val;
            return;
        }
        s[index].first.push_back(sid);
        s[index].second.push_back(val);
    }
    
    int snap() {
        return sid++;
    }
    
    int get(int index, int snap_id) {
        if (s[index].first.empty() || s[index].first[0] > snap_id) {
            return 0;
        }
        
        int i = lower_bound(s[index].first.begin(), s[index].first.end(), snap_id) 
                - s[index].first.begin();

        if (s[index].first.size() <= i || s[index].first[i] != snap_id) i--;
        return s[index].second[i];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */