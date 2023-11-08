class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dist = max(abs(fx-sx), abs(fy-sy));
        if (dist > t) return false;
        if (dist == 0 && t == 1) return false;
        return true;
    }
};