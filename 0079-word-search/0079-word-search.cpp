class Solution {
public:
    bool charExist(vector<vector<char>>& board, string& word, int row, int col, int indexCurr) {
        // cout<<row<<" "<<col<<" "<<board[row][col]<<" "<<indexCurr<<endl;
        if (board[row][col] != word[indexCurr]) return false;
        // cout<<"found\n";

        char character = board[row][col];
        board[row][col] = '0';

        indexCurr++;
        if (indexCurr == word.size()) return true;

        if (row != 0) if (charExist(board, word, row-1, col, indexCurr)) return true;
        if (row+1 != board.size()) if (charExist(board, word, row+1, col, indexCurr)) return true;
        if (col != 0) if (charExist(board, word, row, col-1, indexCurr)) return true;
        if (col+1 != board[0].size()) if (charExist(board, word, row, col+1, indexCurr)) return true;
        board[row][col] = character;
        return false;
    }
    bool exist(vector<vector<char>>& board, string& word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (charExist(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};