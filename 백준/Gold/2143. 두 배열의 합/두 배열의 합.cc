#include <bits/stdc++.h>
using namespace std;

int main() {
    long T;
    cin >> T;

    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    map<long, long> longMap;

    // A 배열의 모든 부 배열 합 계산
    for (int i = 0; i < n; ++i) {
        long sum = 0;
        for (int j = i; j < n; ++j) {
            sum += A[j];
            longMap[sum]++;
        }
    }

    // B 배열의 모든 부 배열 합 계산
    long answer = 0;
    for (int i = 0; i < m; ++i) {
        long sum = 0;
        for (int j = i; j < m; ++j) {
            sum += B[j];
            if (longMap.count(T - sum)) {
                answer += longMap[T - sum];
            }
        }
    }

    cout << answer << endl;
    return 0;
}
