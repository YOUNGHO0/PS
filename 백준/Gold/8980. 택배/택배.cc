#include <bits/stdc++.h>

using namespace std;

int main() {
    int nodeNumber, c;
    cin >> nodeNumber >> c;

    int edgeCount;
    cin >> edgeCount;

    vector<tuple<int, int, int>> arr;

    for (int i = 0; i < edgeCount; i++) {
        int from, to, value;
        cin >> from >> to >> value;
        arr.push_back({to, from, value}); // to 기준으로 정렬하기 위해 바꿈
    }

    // 받는 마을(to) 기준 정렬, 같다면 보내는 마을(from) 기준 정렬
    sort(arr.begin(), arr.end());

    vector<int> load(nodeNumber + 1, 0); // 각 마을까지 트럭에 실린 박스 개수 저장
    int ans = 0;

    for (auto [t, f, v] : arr) {
        // 현재 마을 구간에서 트럭에 실린 박스 중 최댓값 찾기
        int maxLoad = 0;
        for (int i = f; i < t; i++) {
            maxLoad = max(maxLoad, load[i]);
        }

        // 실을 수 있는 박스 개수는 트럭 최대 용량에서 현재 실린 박스를 뺀 값
        int loadable = min(v, c - maxLoad);

        // 박스를 실을 수 있다면 실음
        if (loadable > 0) {
            for (int i = f; i < t; i++) {
                load[i] += loadable;
            }
            ans += loadable;
        }
    }

    cout << ans << endl;
    return 0;
}
