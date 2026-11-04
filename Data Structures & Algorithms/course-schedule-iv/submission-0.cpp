class Solution {
public:
    bool dfs(int u, int v, vector<int>& visited, vector<vector<int>>& adj)
    {
        visited[u] = 1;
        for(auto it : adj[u]){
            if(!visited[it] && it == v){
                return true;
            }else if(!visited[it]){
                if(dfs(it, v, visited, adj)) return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<bool> ans;
        for(auto it : queries){
            int u = it[0];
            int v = it[1];
            vector<int> visited(numCourses, 0);
            bool result = dfs(u, v, visited, adj);
            ans.push_back(result);
        }

        return ans;
    }
};