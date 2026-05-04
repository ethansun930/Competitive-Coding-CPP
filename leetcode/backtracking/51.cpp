#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> ans;
    bool check_board(vector<int>& queens, int row) {
        unordered_set<int> columns;
        for (int i = 0; i <= row; i++) {
            if (columns.find(queens[i]) != columns.end()) {
                return false;
            }
            columns.insert(queens[i]);
        }
        unordered_set<int> diags;
        for (int i = 0; i <= row; i++) {
            if (diags.find(queens[i] - i) != diags.end()) {
                return false;
            }
            diags.insert(queens[i] - i);
        }
        diags.clear();
        for (int i = 0; i <= row; i++) {
            if (diags.find(queens[i] + i) != diags.end()) {
                return false;
            }
            diags.insert(queens[i] + i);
        }
        return true;
    }
    void solve_row(vector<string>& board, vector<int>& queens, int row) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < board.size(); i++) {
            board[row][i] = 'Q';
            queens.push_back(i);
            if (check_board(queens, row)) {
                solve_row(board, queens, row + 1);
            }
            queens.pop_back();
            board[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> queens;
        solve_row(board, queens, 0);
        return ans;
    }
};