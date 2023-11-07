class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for (int i = 0; i < n; i++) dist[i] = ceil(float(dist[i])/float(speed[i]));

        sort(dist.begin(), dist.end());

        int i = 0;
        for (; i < n; i++) if (dist[i] <= i) break;

        return i;
    }
};