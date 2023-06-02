class SmallestInfiniteSet {
public:
    vector<int> InfiniteSet;
    SmallestInfiniteSet() {
        InfiniteSet.push_back(1);
    }
    
    int popSmallest() {
        if (InfiniteSet.size() == 1) {
            int temp = InfiniteSet[0];
            InfiniteSet.pop_back();
            InfiniteSet.push_back(temp + 1);
            return temp;
        }
        else {
            int temp = *(InfiniteSet.end() - 1); 
            InfiniteSet.pop_back();
            return temp;
        }
    }
    
    void addBack(int num) {
        if (InfiniteSet[0] < num) return;
        if (*(InfiniteSet.end() - 1) > num) InfiniteSet.push_back(num);
        else {
            auto it = InfiniteSet.begin();
            while (*it > num) it++;
            if (*it == num) return;
            InfiniteSet.emplace(it, num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */