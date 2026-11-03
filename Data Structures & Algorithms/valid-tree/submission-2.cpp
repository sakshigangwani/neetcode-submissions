class Solution {
public:
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adj)
    {
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it, node, visited, adj)) return true;
            }else if(it != parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(edges.size() != n - 1) return false;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(i, -1, visited, adj)) return false;
            }
        }
        return true;
    }
};
