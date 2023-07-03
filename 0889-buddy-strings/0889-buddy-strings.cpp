class Solution
{
    public:
        bool buddyStrings(string s, string goal)
        {
            if (s.size() != goal.size()) return false;
            int diff = 0, n = s.size();
            vector<int> sw;

            for (int i = 0; i < n; i++)
                if (s[i] != goal[i]) sw.push_back(i);
            if (sw.empty())
            {
                if (n > 26) return true;
                for (int i = 0; i < n; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (s[i] == s[j]) return true;
                    }
                }

                return false;
            }
            else if (sw.size() != 2) return false;

            if (s[sw[0]] == goal[sw[1]] && s[sw[1]] == goal[sw[0]]) return true;
            return false;
        }
};