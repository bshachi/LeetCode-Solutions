class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> intervals;
        for (int i = 0; i <= n; i++) intervals.push_back({i - ranges[i], i + ranges[i]});
        sort(intervals.begin(), intervals.end());

        int minimumTaps = 0, i = 0, wateredTill = 0, maxPossibleWatering = 0;
        while (wateredTill < n && i <= n) {
            while (i <= n && intervals[i].first <= wateredTill) {
                if (intervals[i].second > maxPossibleWatering) {
                    maxPossibleWatering = intervals[i].second;
                }
                i++;
            }
            if (wateredTill == maxPossibleWatering) return -1;
            wateredTill = maxPossibleWatering;
            minimumTaps++;
        }
        if (wateredTill < n) return -1;
        return minimumTaps;
    }
};