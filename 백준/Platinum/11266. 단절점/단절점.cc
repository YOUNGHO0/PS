#include <bits/stdc++.h>

using namespace std;

int num = 1;
int order[100005] = {0};
int deleteNode[100005] = {0};
map<int, vector<int>> edgeList;

int dfs(int pos, bool isRoot) {
    order[pos] = num++;
    int ans = order[pos];
    int degree = 0;

    for (int i = 0; i < edgeList[pos].size(); i++) {
        int next = edgeList[pos][i];

        if (order[next] != 0) {  // 이미 방문한 노드
            ans = min(ans, order[next]);
            continue;
        }

        degree++;
        int ret = dfs(next, false);

        // 단절점 조건
        if (!isRoot && ret >= order[pos]) {
            deleteNode[pos] = 1;
        }

        ans = min(ret, ans);
    }

    // 루트 노드의 경우 차수가 2 이상일 때 단절점
    if (isRoot && degree >= 2) {
        deleteNode[pos] = 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    int vertexNumber, edgeNumber;
    cin >> vertexNumber >> edgeNumber;

    int from, to;
    for (int i = 0; i < edgeNumber; i++) {
        cin >> from >> to;
        edgeList[from].push_back(to);
        edgeList[to].push_back(from);
    }

    // 모든 정점에 대해 DFS 실행
    for (int i = 1; i <= vertexNumber; i++) {
        if (order[i] == 0) {
            dfs(i, true);
        }
    }

    vector<int> answer;

    // 단절점 출력
    for (int i = 1; i <= vertexNumber; i++) {
        if (deleteNode[i] == 1) {
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << '\n';

    return 0;
}
