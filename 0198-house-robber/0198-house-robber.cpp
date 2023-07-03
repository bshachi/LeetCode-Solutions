class Solution
{
    public:
        int rob(vector<int> &nums)
        {
            int ans = 0, prev = 0, n = nums.size(), temp;
            bool last = false;
            for (int x: nums)
            {
                if (!last)
                {
                    prev = ans;
                    ans += x;
                    last = true;
                }
                else
                {
                    if (prev + x > ans)
                    {
                        temp = ans;
                        ans = prev + x;
                        prev = temp;
                    }
                    else last = false;
                }
            }
            return ans;
        }
};