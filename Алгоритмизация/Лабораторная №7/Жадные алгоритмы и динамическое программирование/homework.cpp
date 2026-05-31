#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    std::cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = row[j] - '0';
        }
    }

    vector<vector<int>> mx(n, vector<int>(m, 0));

    mx[n - 1][0] = grid[n - 1][0];

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {

            if (i == n - 1 && j == 0) continue;

            int from_bottom = 0;
            int from_left = 0;

            if (i + 1 < n) {
                from_bottom = mx[i + 1][j];
            }

            if (j - 1 >= 0) {
                from_left = mx[i][j - 1];
            }

            if (i == n - 1) {
                mx[i][j] = from_left + grid[i][j];
            }
            else if (j == 0) {
                mx[i][j] = from_bottom + grid[i][j];
            }
            else {
                mx[i][j] = max(from_bottom, from_left) + grid[i][j];
            }
        }
    }

    std::cout << mx[0][m - 1] << std::endl;

    return 0;
}