#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;
int visited[MAXN], instack[MAXN], low[MAXN], nodeCount, sccCount;
stack<int> stk;
vector<int> sccs[MAXN];  // 각 SCC에 속한 노드들
map<int, vector<int>> vmap;  // 그래프
int sccId[MAXN];  // 각 노드의 SCC 번호
vector<int> sccGraph[MAXN];  // SCC 간 그래프
int sccIndegree[MAXN];  // SCC의 진입 차수

// Tarjan 알고리즘을 이용한 DFS
int dfs(int nodeNumber) {
    visited[nodeNumber] = low[nodeNumber] = ++nodeCount;
    instack[nodeNumber] = 1;
    stk.push(nodeNumber);

    for (int neighbor : vmap[nodeNumber]) {
        if (visited[neighbor] == 0) {
            low[nodeNumber] = min(low[nodeNumber], dfs(neighbor));
        } else if (instack[neighbor]) {
            low[nodeNumber] = min(low[nodeNumber], visited[neighbor]);
        }
    }

    // SCC 찾기
    if (visited[nodeNumber] == low[nodeNumber]) {
        ++sccCount;
        vector<int> scc;
        while (true) {
            int topNode = stk.top();
            stk.pop();
            instack[topNode] = 0;
            scc.push_back(topNode);
            sccId[topNode] = sccCount;  // SCC 번호 할당
            if (topNode == nodeNumber) break;
        }
        sccs[sccCount] = scc;
    }

    return low[nodeNumber];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // 테스트 케이스 수

    while (t--) {
        int n, m;
        cin >> n >> m;  // n: 도미노 개수, m: 관계 개수

        // 그래프 초기화
        vmap.clear();
        for (int i = 0; i <= n; ++i) {
            sccs[i].clear();
            sccGraph[i].clear();
            sccIndegree[i] = 0;
        }
        memset(visited, 0, sizeof(visited));
        memset(instack, 0, sizeof(instack));
        memset(sccId, 0, sizeof(sccId));
        nodeCount = 0;
        sccCount = 0;

        // 관계 입력
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            vmap[x].push_back(y);
        }

        // SCC 찾기
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }

        // SCC 간의 그래프 구성
        for (auto &[node, neighbors] : vmap) {
            for (int neighbor : neighbors) {
                if (sccId[node] != sccId[neighbor]) {  // 다른 SCC로 이동하는 간선
                    sccGraph[sccId[node]].push_back(sccId[neighbor]);
                    sccIndegree[sccId[neighbor]]++;  // 진입 차수 증가
                }
            }
        }

        // 진입 차수가 0인 SCC의 개수 세기
        int answer = 0;
        for (int i = 1; i <= sccCount; ++i) {
            if (sccIndegree[i] == 0) {
                answer++;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
