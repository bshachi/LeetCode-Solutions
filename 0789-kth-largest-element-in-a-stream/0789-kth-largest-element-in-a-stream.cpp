class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> n;
    int k;
    KthLargest(int kval, vector<int>& nums) {
        for(auto i = nums.begin(); i<nums.end(); i++)
        {
            n.push(*i);
            if (n.size()>kval) n.pop();
        }
        k = kval;
    }
    
    int add(int val) {
        n.push(val);
        if (n.size()>k) n.pop();
        return n.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */