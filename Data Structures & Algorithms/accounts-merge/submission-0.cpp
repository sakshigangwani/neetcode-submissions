class DisjointSet {
        public:
            vector<int> size, parent;
            DisjointSet(int n){
                size.resize(n, 1);
                parent.resize(n);
                for(int i = 0; i < n; i++){
                    parent[i] = i;
                }
            }

            int findParent(int u){
                if(parent[u] == u){
                    return u;
                }
                return parent[u] = findParent(parent[u]);
            }

            void unionBySize(int u, int v){
                int pu = findParent(u);
                int pv = findParent(v);
                if(pu == pv) return;
                if(size[pu] < size[pv]){
                    parent[pu] = pv;
                    size[pv] += size[pu];
                }else{
                    parent[pv] = pu;
                    size[pu] += size[pv];
                }
            }
    };
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }else{
                    ds.unionBySize(i, mp[accounts[i][j]]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);

        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};