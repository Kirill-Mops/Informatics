#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> createBoard(const vector<int>& pfer, int n) {
    vector<string> board(n, string(n, '.'));
    for (int row = 0; row < n; ++row) {
        board[row][pfer[row]] = 'Q';
    }
    return board;
}

void base(int row, int n, vector<int>& pfer,
    vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
    vector<vector<string>>& results) {
    if (row == n) {
        results.push_back(createBoard(pfer, n));
        return;
    }

    for (int col = 0; col < n; ++col) {
        int d1 = row - col + n; 
        int d2 = row + col;

        if (cols[col] || diag1[d1] || diag2[d2]) {
            continue;
        }

        pfer[row] = col;
        cols[col] = diag1[d1] = diag2[d2] = true;

        base(row + 1, n, pfer, cols, diag1, diag2, results);

        cols[col] = diag1[d1] = diag2[d2] = false;
    }
}

int main() {
    int n;
    std::cin >> n;

    vector<int> pfer(n);

    vector<bool> cols(n, false);
    vector<bool> diag1(2 * n, false);
    vector<bool> diag2(2 * n, false);

    vector<vector<string>> results;

    base(0, n, pfer, cols, diag1, diag2, results);

    if (results.empty()) {
        std::cout << "Решений нет" << std::endl;
        return 0;
    }

    for (int i = 0; i < results.size(); ++i) {
        std::cout << "[" << std::endl;
        for (int row = 0; row < n; ++row) {
            std::cout << "  \"" << results[i][row] << "\"";
            if (row < n - 1) std::cout << "," << std::endl;
            else std::cout << "\n";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
