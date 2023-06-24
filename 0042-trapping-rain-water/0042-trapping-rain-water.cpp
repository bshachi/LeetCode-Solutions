class Solution
{
    public:

        int trap(vector<int> &height)
        {
            vector<pair<int, int>> local_maximas;
            unordered_set<int> unvisited_maximas;

            int m, ans = 0, i = 0, n = height.size();

            while (i < n - 1 && height[i] <= height[i + 1]) i++;
            if (i != n - 1)
            {
                local_maximas.push_back({ height[i],
                    i });
                unvisited_maximas.insert(i);
            }

            while (i < n - 1)
            {
                while (i < n - 1 && height[i] >= height[i + 1]) i++;
                if (i == n - 1) break;

                while (i < n - 1 && height[i] <= height[i + 1]) i++;
                local_maximas.push_back({ height[i],
                    i });
                unvisited_maximas.insert(i);
            }

            sort(local_maximas.begin(), local_maximas.end(), greater<pair<int, int>> ());

            m = local_maximas.size();
            for (int i = 1; i < m; i++)
            {
                if (unvisited_maximas.find(local_maximas[i].second) == unvisited_maximas.end()) 
                    continue;
                int w = INT_MAX;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (abs(local_maximas[j].second - local_maximas[i].second) < abs(w - local_maximas[i].second)) 
                        w = local_maximas[j].second;
                }
                ans += (abs(local_maximas[i].second - w) - 1) *local_maximas[i].first;
                for (int j = min(local_maximas[i].second, w) + 1; j < max(local_maximas[i].second, w); j++)
                {
                    ans -= min(height[j], local_maximas[i].first);
                    unvisited_maximas.erase(j);
                }
            }
            return ans;
        }
};