class Solution {
public:
    bool checkBox(vector<vector<char>>& board, int r, int c){
        vector<int> seen(10, 0);
        for(int i = r; i < r + 3; i++){
            for(int j = c; j < c + 3; j++){
                if(board[i][j] == '.')
                    continue;
                int x = board[i][j] - '0';
                if(seen[x])
                    return false;
                seen[x] = 1;
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board, int c){
        vector<int> seen(10, 0);
        for(int i = 0; i < 9; i++){
            if(board[i][c] == '.')
                continue;
            int x = board[i][c] - '0';
            if(seen[x])
                return false;
            seen[x] = 1;
        }
        return true;
    }
    bool checkRow(vector<vector<char>>& board, int r){
        vector<int> seen(10, 0);
        for(int i = 0; i < 9; i++){
            if(board[r][i] == '.')
                continue;
            int x = board[r][i] - '0';
            if(seen[x])
                return false;
            seen[x] = 1;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        // check all rows and cols;
        for(int i = 0; i < n; i++){
            if(!checkRow(board, i))
                return false;
            
            if(!checkCol(board, i))
                return false;
        }

        // check all boxes;
        for(int i = 0; i < n; i += 3){
            for(int j = 0; j < n; j += 3){
                if(!checkBox(board, i, j))
                    return false;
            }
        }
        return true;
    }
};
