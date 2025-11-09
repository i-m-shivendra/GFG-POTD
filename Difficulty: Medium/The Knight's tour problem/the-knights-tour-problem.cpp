class Solution {
public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        
        // All knight possible moves
        int dx[8] = {2,1,-1,-2,-2,-1,1,2};
        int dy[8] = {1,2,2,1,-1,-2,-2,-1};

        board[0][0] = 0;  // starting at (0,0) with move 0

        if (solve(0, 0, 1, board, dx, dy, n))
            return board;

        return {}; // return empty if solution not found
    }

    bool solve(int x, int y, int move, vector<vector<int>>& board,
               int dx[], int dy[], int n) {
        
        if (move == n * n) return true;   // tour complete
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // valid and unvisited
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == -1) {
                board[nx][ny] = move;
                
                if (solve(nx, ny, move + 1, board, dx, dy, n))
                    return true;

                board[nx][ny] = -1; // backtrack
            }
        }
        return false;
    }
};
