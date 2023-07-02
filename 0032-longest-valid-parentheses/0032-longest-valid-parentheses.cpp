class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            int n = s.size(), ans = 0;
            vector<int> l(n, 0);

            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == '(' && s[i + 1] == ')')
                {
                    l[i] = 2;
                    ans = 2;
                }
            }

            if (ans == 0) return 0;
            bool final = false;
            int m = n - 3;

            while (!final && m >= 0)
            {
                final = true;

                for (int i = m; i >= 0; i--)
                {
                    if (l[i] && i + l[i] < n && l[i + l[i]])
                    {
                        l[i] += l[i + l[i]];
                        final = false;
                    }

                    if (l[i] == 0 && s[i] == '(' && l[i + 1] && i + 1 + l[i + 1] < n && s[i + 1 + l[i + 1]] == ')')
                    {
                        l[i] = l[i + 1] + 2;
                        final = false;
                    }
                }

                m--;
            }

            for (int x: l) if (x > ans) ans = x;
            return ans;
        }
};