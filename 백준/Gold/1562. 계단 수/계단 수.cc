#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int main() {
    int number;
    cin >> number;

    int dp[101][1 << 10][10] = {0};

    // 초기값 설정
    for (int i = 1; i < 10; i++) {
        dp[1][1 << i][i] = 1;
    }

    // DP 진행
    for (int i = 1; i < number; i++) {
        for (int k = 0; k < (1 << 10); k++) {
            for (int j = 0; j < 10; j++) {
                if ((k & (1 << j)) == 0) continue; // 현재 숫자 j가 없는 상태면 무시
                if (dp[i][k][j] == 0) continue;   // 값이 0이면 연산 필요 없음

                int before = j - 1;
                if (before >= 0) { // 0도 포함해야 함
                    dp[i + 1][k | (1 << before)][before] += dp[i][k][j];
                    dp[i + 1][k | (1 << before)][before] %= MOD;
                }

                int after = j + 1;
                if (after < 10) {
                    dp[i + 1][k | (1 << after)][after] += dp[i][k][j];
                    dp[i + 1][k | (1 << after)][after] %= MOD;
                }
            }
        }
    }

    // 정답 계산
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer = (answer + dp[number][(1 << 10) - 1][i]) % MOD;
    }

    cout << answer << '\n';
    return 0;
}
