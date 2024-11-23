#include <bits/stdc++.h>
using namespace std;

int parent[10002];  // 부모 배열

// Find with path compression
int find(int a) {
    if (parent[a] != a) {
        parent[a] = find(parent[a]);  // 경로 압축
    }
    return parent[a];
}

// Union without rank
void unionNumber(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb) {
        parent[pb] = pa;  // 두 집합을 합침
    }
}

class Edge {
public:
    int from, to;
    long value;

    Edge(int from, int to, long value) : from(from), to(to), value(value) {}
};

// 우선순위 큐 비교 함수
struct CompareEdge {
    bool operator()(const Edge& a, const Edge& b) {
        return a.value > b.value;  // 가중치가 작은 간선이 우선으로 오도록 설정
    }
};

int main() {
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;

    priority_queue<Edge, vector<Edge>, CompareEdge> pq;  // 우선순위 큐 (Min-Heap)

    int from, to;
    long value;
    for (int i = 0; i < edgeNum; i++) {
        cin >> from >> to >> value;
        pq.push(Edge(from, to, value));  // 간선을 우선순위 큐에 삽입
    }

    // 부모 배열 초기화: 각 정점은 자기 자신을 부모로 설정
    for (int i = 1; i <= nodeNum; i++) {
        parent[i] = i;
    }

    long answer = 0;

    // Kruskal 알고리즘: 간선들을 하나씩 처리
    int edgeCount = 0;
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        if (find(e.from) != find(e.to)) {  // 두 정점이 서로 연결되어 있지 않으면
            unionNumber(e.from, e.to);  // 두 집합을 합침
            answer += e.value;  // 해당 간선의 가중치를 MST에 추가
            edgeCount++;

            // MST는 V-1개의 간선으로 구성됨
            if (edgeCount == nodeNum - 1) {
                break;
            }
        }
    }

    cout << answer << endl;  // 최소 스패닝 트리의 가중치 합 출력

    return 0;
}
