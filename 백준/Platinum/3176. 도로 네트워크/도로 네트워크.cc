#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
const int LOG = 20;

int parent[MAX_N+1][LOG];
int maxArr[MAX_N+1][LOG];
int minArr[MAX_N+1][LOG];
int nodeDepth[MAX_N+1];

vector<vector<pair<int,int>>> adj(MAX_N+1);

void findParent(int pNum, int cur, int depth, int value){
    parent[cur][0] = pNum;
    nodeDepth[cur] = depth;
    maxArr[cur][0] = minArr[cur][0] = value;

    for(auto &next : adj[cur]) {
        if(next.first != pNum) {
            findParent(cur, next.first, depth + 1, next.second);
        }
    }
}

pair<int, int> findNode(int a, int b) {
    int minResult = INT_MAX;
    int maxResult = INT_MIN;

    if(nodeDepth[a] < nodeDepth[b]) swap(a, b);
    
    int remain = nodeDepth[a] - nodeDepth[b];
    for(int i = LOG-1; i >= 0; i--) {
        if(remain & (1 << i)) {
            minResult = min(minResult, minArr[a][i]);
            maxResult = max(maxResult, maxArr[a][i]);
            a = parent[a][i];
        }
    }

    if(a == b) return {minResult, maxResult};

    for(int i = LOG-1; i >= 0; i--) {
        if(parent[a][i] != parent[b][i]) {
            minResult = min({minResult, minArr[a][i], minArr[b][i]});
            maxResult = max({maxResult, maxArr[a][i], maxArr[b][i]});
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    minResult = min({minResult, minArr[a][0], minArr[b][0]});
    maxResult = max({maxResult, maxArr[a][0], maxArr[b][0]});

    return {minResult, maxResult};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 1; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].emplace_back(B, C);
        adj[B].emplace_back(A, C);
    }

    findParent(0, 1, 0, 0);

    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= N; j++) {
            if(parent[j][i-1] != 0) {
                parent[j][i] = parent[parent[j][i-1]][i-1];
                minArr[j][i] = min(minArr[j][i-1], minArr[parent[j][i-1]][i-1]);
                maxArr[j][i] = max(maxArr[j][i-1], maxArr[parent[j][i-1]][i-1]);
            }
        }
    }

    int K;
    cin >> K;
    while(K--) {
        int from, to;
        cin >> from >> to;
        auto [minVal, maxVal] = findNode(from, to);
        cout << minVal << " " << maxVal << "\n";
    }

    return 0;
}
