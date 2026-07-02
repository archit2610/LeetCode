class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows,coloumns,boxes;

        for (int i = 0; i < 9;++i){
            for (int j = 0 ; j < 9;++j){
                if (board[i][j] == '.')
                    continue;
                char value = board[i][j];
                int box = (i/3)*3 + (j/3);
                if(rows[i].count(value) || coloumns[j].count(value) || boxes[box].count(value)){
                    return false;
                }
                rows[i].insert(value);
                coloumns[j].insert(value);
                boxes[box].insert(value);
            }
        }
        return true;
    }
};