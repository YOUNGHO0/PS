#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> workList[1002];  // 각 사람이 가능한 작업 리스트
int work[10002];  // 각 일에 할당된 사람 (0이면 할당되지 않음)
bool visited[1002];  // DFS 방문 여부 체크

bool canVisit(int who) {
    for (int job : workList[who]) {
        if (visited[job]) continue;
        visited[job] = true;  // 방문 체크

        // 현재 일이 비어 있거나, 기존 사람이 다른 일로 옮길 수 있다면
        if (work[job] == 0 || canVisit(work[job])) {
            work[job] = who;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++) {
            int job;
            cin >> job;
            workList[i].push_back(job);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        fill(visited, visited + m + 1, false);  // 매칭 시도할 때마다 방문 배열 초기화
        if (canVisit(i)) ans++;
    }

    cout << ans << "\n";

    return 0;
}
