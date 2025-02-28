#include <bits/stdc++.h>
using namespace std;

map<int, set<pair<int, int>>> graph;
int N, M;

void dij(vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        auto [value, nodeNum] = pq.top();
        pq.pop();
        
        if (dist[nodeNum] < value) continue;
        
        for (auto [to, nodeVal] : graph[nodeNum]) {
            if (value + nodeVal < dist[to]) {
                dist[to] = value + nodeVal;
                pq.push({dist[to], to});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    vector<vector<int>> edges;
    
    for (int i = 0; i < M; i++) {
        int from, to, value;
        cin >> from >> to >> value;
        graph[from].insert({to, value});
        graph[to].insert({from, value});
        edges.push_back({from, to, value});
    }
    
   
    vector<int> baseDist(N + 1, INT_MAX);
    dij(baseDist);
    if (baseDist[N] == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    
    int minNum = baseDist[N], maxNum = INT_MIN;
    
   
    for (auto& edge : edges) {
        int from = edge[0], to = edge[1], value = edge[2];
        
        if (baseDist[from] + value == baseDist[to] || baseDist[to] + value == baseDist[from]) {
            
            graph[from].erase({to, value});
            graph[to].erase({from, value});
            
            vector<int> newDist(N + 1, INT_MAX);
            dij(newDist);
            
            maxNum = max(maxNum, newDist[N]);
            
            graph[from].insert({to, value});
            graph[to].insert({from, value});
        }
    }
    
    if (maxNum == INT_MAX) cout << -1 << endl;
    else cout << maxNum - minNum << endl;
    
    return 0;
}
