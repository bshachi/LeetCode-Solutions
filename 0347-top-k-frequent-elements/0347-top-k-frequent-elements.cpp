class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        unordered_map<int,int> freq;
        int n = nums.size();
        vector<int> ans;


        for (int i = 0; i<n; i++) freq[nums[i]]++;
        for (auto x:freq) {
            pq.push(make_pair(x.second, x.first));
            if (pq.size() > k) pq.pop();
        }


        while (not(pq.empty())) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};