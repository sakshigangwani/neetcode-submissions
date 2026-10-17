class Solution {
public:
    void dfs(int row, int col, int& count, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        count++;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                dfs(nrow, ncol, count, grid, visited);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int count = 0;
                    dfs(i, j, count, grid, visited);
                    maxArea = max(maxArea, count); 
                }
            }
        }
        return maxArea;
    }
};
