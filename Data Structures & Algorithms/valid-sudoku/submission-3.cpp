class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> boxes[9];
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                char ch = board[i][j];

                if(ch == '.'){
                    continue;
                }

                int box = (i / 3) * 3 + (j / 3);

                if(rows[i].count(ch) || cols[j].count(ch) || boxes[box].count(ch)){
                    return false;
                }

                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[box].insert(ch);
            }
        }
        return true;
    }
};
