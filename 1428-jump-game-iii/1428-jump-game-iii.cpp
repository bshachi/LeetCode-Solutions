class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if (arr[start] == 0) return true;

        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int temp = q.front() - arr[q.front()];
            if (temp < n && temp >= 0) {
                if (arr[temp] == 0) return true;
                q.push(temp);
            }

            temp = q.front() + arr[q.front()];
            if (temp < n && temp >= 0) {
                if (arr[temp] == 0) return true;
                q.push(temp);
            } 

            arr[q.front()] = n;
            q.pop();
        }
        return false;
    }
};