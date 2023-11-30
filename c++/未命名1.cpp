#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<string>& board, int row, int col, int N) {
    // 检查同一列是否有其他皇后
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    
    // 检查左上方对角线是否有其他皇后
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }
    
    // 检查右上方对角线是否有其他皇后
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < N) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j++;
    }
    
    return true;
}

void backtrack(vector<vector<string> >& result, vector<string>& board, int row, int N) {
    if (row == N) {
        // 找到一个可行解
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // 将皇后放置在当前位置
            board[row][col] = 'Q';
            // 继续下一行的回溯
            backtrack(result, board, row + 1, N);
            // 撤销当前位置的皇后
            board[row][col] = '.';
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    vector<string> board(n, string(n, '.')); // 初始化棋盘
    
    backtrack(result, board, 0, n);
    
    return result;
}

int main() {
    int n;
    cout << "请输入 N 的值：";
    cin >> n;
    
    vector<vector<string> > solution = solveNQueens(n);
    
    cout << "共找到 " << solution.size() << " 个解：" << endl;
    for (int i = 0; i < solution.size(); i++) {
        cout << "解 " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
