#include <bits/stdc++.h>
using namespace std;

const int INF = 1000;

int dp[1001][1001][2];

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    int na = a.size(), nb = b.size();

    if (na > nb) {
        cout << -1 << endl;
        return 0;
    }

    // 초기화
    dp[0][0][0] = 0;
    dp[0][0][1] = INF;
    for (int i = 1; i <= nb; i++) {
        dp[0][i][0] = INF;
        dp[0][i][1] = 1;
    }

    // DP 진행
    for (int i = 0; i < na; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j][0] = dp[i + 1][j][1] = INF;
        }
        for (int j = i; j < nb; j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1][0] = min(dp[i][j][0], dp[i][j][1]);
            } else {
                dp[i + 1][j + 1][0] = INF;
            }
            dp[i + 1][j + 1][1] = min(dp[i + 1][j][0] + 1, dp[i + 1][j][1]);
        }
    }

    int result = min(dp[na][nb][0], dp[na][nb][1]);
    cout << (result >= INF ? -1 : result) << endl;

    return 0;
}
