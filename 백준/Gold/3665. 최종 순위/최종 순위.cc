#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
bool cycle = false;
vector<int> visited;
vector<bool> inStack;

void dfs(const vector<vector<int>>& graph, int node) {
    visited[node] = 1;
    inStack[node] = true;

    for (int next : graph[node]) {
        if (visited[next] == 0) {
            dfs(graph, next);
        } else if (inStack[next]) {
            cycle = true;
            return;
        }
    }

    inStack[node] = false;
    ans.push_back(node);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> nodeList(n);

    for (int i = 0; i < n; i++) {
        cin >> nodeList[i];
    }

    // 작년의 순위를 기반으로 그래프를 구성
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            graph[nodeList[i]].push_back(nodeList[j]);
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        // 간선 방향을 변경
        auto it = find(graph[a].begin(), graph[a].end(), b);
        if (it != graph[a].end()) {
            graph[a].erase(it);
            graph[b].push_back(a);
        } else {
            it = find(graph[b].begin(), graph[b].end(), a);
            if (it != graph[b].end()) {
                graph[b].erase(it);
                graph[a].push_back(b);
            }
        }
    }

    visited.assign(n + 1, 0);
    inStack.assign(n + 1, false);
    ans.clear();
    cycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[nodeList[i]]) {
            dfs(graph, nodeList[i]);
        }
    }

    if (cycle) {
        cout << "IMPOSSIBLE\n";
    } else if (ans.size() != n) {
        cout << "?\n";
    } else {
        reverse(ans.begin(), ans.end());
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        solve();
    }

    return 0;
}
