#include <bits/stdc++.h>
using namespace std;

int main() {
    int col, row, height;
    cin >> col >> row >> height;

    vector<vector<vector<int>>> arr(height, vector<vector<int>>(row, vector<int>(col, 0)));
    queue<tuple<int, int, int>> myQueue;
    int targetCount = 0, curCount = 0;

    for (int h = 0; h < height; h++) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                cin >> arr[h][r][c];
                if (arr[h][r][c] == 1) {
                    myQueue.push({h, r, c});
                } else if (arr[h][r][c] == 0) {
                    targetCount++;
                }
            }
        }
    }

    if (targetCount == 0) {
        cout << 0 << endl;
        return 0;
    }

    int day = 0;
    int dz[] = {0, 0, 0, 0, 1, -1};
    int dy[] = {0, 0, 1, -1, 0, 0};
    int dx[] = {1, -1, 0, 0, 0, 0};

    while (!myQueue.empty()) {
        int num = myQueue.size();
        for (int i = 0; i < num; i++) {
            auto [cz, cy, cx] = myQueue.front();
            myQueue.pop();

            for (int d = 0; d < 6; d++) {
                int nz = cz + dz[d];
                int ny = cy + dy[d];
                int nx = cx + dx[d];

                if (nx < 0 || nx >= col || ny < 0 || ny >= row || nz < 0 || nz >= height) continue;
                if (arr[nz][ny][nx] == 0) {
                    curCount++;
                    arr[nz][ny][nx] = 1;
                    myQueue.push({nz, ny, nx});
                }
            }
        }
        day++;
    }

    if (curCount != targetCount) {
        cout << -1 << endl;
    } else {
        cout << day - 1 << endl;
    }

    return 0;
}
