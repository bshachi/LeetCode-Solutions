class Solution {
private:
    vector<int> sz, par;
    void add_edge(int u, int v) {
        int pu = ulp(u), pv = ulp(v);
        if (sz[pu] > sz[pv]) {
            par[pv] = pu;
            sz[pu] += sz[pv];
        }
        else {
            par[pu] = pv;
            sz[pv] += sz[pu];
        }
    }
    int ulp(int v) {
        if (par[v] == v) return v;
        return par[v] = ulp(par[v]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        sz.resize(n, 1);
    
        for (int  i = 0; i < n; i++) {
            par.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.push_back({(abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])), i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int edgeCount = 0, cost = 0, i = 0;
        while (edgeCount < n - 1) {
            if (ulp(edges[i][1]) == ulp(edges[i][2])) {
                i++;
                continue;
            }
            add_edge(edges[i][1], edges[i][2]);
            edgeCount++;
            cost += edges[i][0];
            i++;
        }
        return cost;
        
    }
};