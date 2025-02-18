#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int number, nodeCount, k;
    cin >> number >> nodeCount >> k;

    vector<vector<pair<int, int>>> graph(number + 1);
    for (int i = 0; i < nodeCount; i++) {
        int from, to, value;
        cin >> from >> to >> value;
        graph[from].emplace_back(to, value);
    }

    // K번째 최단 경로를 저장하는 최소 힙
    vector<priority_queue<int>> dist(number + 1);

    // 다익스트라 우선순위 큐 (최소 힙)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1); // (비용, 정점)
    dist[1].push(0);

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        for (auto [next, weight] : graph[node]) {
            int newCost = cost + weight;

            if (dist[next].size() < k) { // k개 이하라면 그냥 추가
                dist[next].push(newCost);
                pq.emplace(newCost, next);
            } 
            else if (dist[next].top() > newCost) { // 기존 k개 중 최대값보다 작으면 교체
                dist[next].pop();
                dist[next].push(newCost);
                pq.emplace(newCost, next);
            }
        }
    }

    for (int i = 1; i <= number; i++) {
        if (dist[i].size() < k) {
            cout << -1 << '\n';
        } else {
            cout << dist[i].top() << '\n';
        }
    }

    return 0;
}
