class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int j, k, CurrentSum, MinDifference = INT_MAX, n = nums.size();

        for (int i = 0; i < n-2; i++) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                CurrentSum = nums[i] + nums[j] + nums[k];
                if (CurrentSum < target) j++;
                else if (CurrentSum > target) k--;
                else return target;

                if (abs(CurrentSum - target) < abs(MinDifference)) 
                    MinDifference = CurrentSum - target;
            }
        }

        return (MinDifference + target);
    }
};