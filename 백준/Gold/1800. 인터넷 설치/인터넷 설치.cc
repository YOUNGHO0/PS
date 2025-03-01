#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N, P, K;
vector<vector<pair<int, int>>> graph;

// 최대 비용을 제한했을 때 1번 -> N번까지 연결이 가능한지 확인하는 함수
bool canConnect(int maxCost) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N + 1, INF);
    pq.emplace(0, 1); // (비용, 시작점)
    dist[1] = 0;
    
    while (!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if (dist[node] < cost) continue;
        
        for (auto [next, weight] : graph[node]) {
            int newCost = cost + (weight > maxCost ? 1 : 0); // 최대 비용 초과 시 카운트 증가
            if (newCost < dist[next]) {
                dist[next] = newCost;
                pq.emplace(newCost, next);
            }
        }
    }
    return dist[N] <= K; // K개 이하로 초과한 경우만 연결 가능
}

int binarySearch() {
    int left = 0, right = 1'000'000, answer = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canConnect(mid)) {
            answer = mid;
            right = mid - 1; // 더 작은 최댓값을 찾기 위해
        } else {
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> P >> K;
    graph.resize(N + 1);
    
    for (int i = 0; i < P; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    cout << binarySearch() << '\n';
    return 0;
}
