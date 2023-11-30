#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<string>& board, int row, int col, int N) {
    // ���ͬһ���Ƿ��������ʺ�
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    
    // ������Ϸ��Խ����Ƿ��������ʺ�
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }
    
    // ������Ϸ��Խ����Ƿ��������ʺ�
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
        // �ҵ�һ�����н�
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // ���ʺ�����ڵ�ǰλ��
            board[row][col] = 'Q';
            // ������һ�еĻ���
            backtrack(result, board, row + 1, N);
            // ������ǰλ�õĻʺ�
            board[row][col] = '.';
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    vector<string> board(n, string(n, '.')); // ��ʼ������
    
    backtrack(result, board, 0, n);
    
    return result;
}

int main() {
    int n;
    cout << "������ N ��ֵ��";
    cin >> n;
    
    vector<vector<string> > solution = solveNQueens(n);
    
    cout << "���ҵ� " << solution.size() << " ���⣺" << endl;
    for (int i = 0; i < solution.size(); i++) {
        cout << "�� " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
