class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string o:operations) {
            if (o[1] == '+') ans++;
            else ans--;
        }

        return ans;
    }
};