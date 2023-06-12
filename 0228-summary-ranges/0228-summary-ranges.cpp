class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int s = 0;
        int e = 0;
        int n = nums.size();
        vector<string> ans;
        string curr;

        while (e < n) {
            if (!(e == n - 1) && nums[e] + 1 == nums[e+1]) {
                e++;
                continue;
            }
            curr = "";
            curr += to_string(nums[s]);

            if (e > s) {
                curr += "->" + to_string(nums[e]);
            }

            e++;
            s = e;
            ans.push_back(curr);
        }

        return ans;
    }
};