#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;
int pos[MAX_N + 10]; // DVD의 현재 위치 (1-based, DVD 번호 1~N)

class SegmentTree {
public:
    vector<int> tree;
    int size; // 전체 leaf 개수, NM = N + M

    void init(int n) { // n: NM (전체 칸의 수)
        size = n;
        tree.assign(n * 4, 0);
    }

    // idx 위치의 값을 val로 설정하는 update 함수
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(node * 2, start, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // [l, r] 구간의 합을 구하는 query 함수
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(node * 2, start, mid, l, r) +
               query(node * 2 + 1, mid + 1, end, l, r);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    while(TC--){
        int N, M;
        cin >> N >> M;
        int NM = N + M;  // 전체 DVD를 놓을 수 있는 칸의 수

        SegmentTree seg;
        seg.init(NM);

        // DVD 초기 위치: DVD i는 pos[i] = M + i 에 놓인다.
        for (int i = 1; i <= N; i++){
            pos[i] = M + i;
            seg.update(1, 1, NM, pos[i], 1);
        }

        int next = M; // 다음에 DVD를 옮겨야 할 위치 (맨 위쪽, 1~M 영역)
        for (int i = 0; i < M; i++){
            int target;
            cin >> target;

            // DVD target 위에 있는 DVD 개수는 [1, pos[target]-1] 구간의 합
            int answer = seg.query(1, 1, NM, 1, pos[target] - 1);
            cout << answer << " ";

            // 기존 위치에서 DVD 제거
            seg.update(1, 1, NM, pos[target], 0);
            // DVD를 가장 위로 옮김
            pos[target] = next;
            seg.update(1, 1, NM, pos[target], 1);
            next--;  // 다음 새 위치 (위로 올릴 위치) 갱신
        }
        cout << "\n";
    }
    return 0;
}
