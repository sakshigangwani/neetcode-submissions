
class Solution {
public:
    vector<int> parent, size;
    
    int findParent(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if(findParent(u) == findParent(v)) {
                return {u, v};
            }

            unionBySize(u, v);
        }

        return {};
    }
};
