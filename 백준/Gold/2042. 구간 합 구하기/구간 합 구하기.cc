#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int n, m, k;
vector<ll> arr;
vector<ll> seg_tree;

void input() {
    cin >> n >> m >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

ll build_segment_tree(int node, int start, int end) {
    if (start == end) return seg_tree[node] = arr[start];

    int mid = (start + end) / 2;
    ll left_sum = build_segment_tree(node * 2, start, mid);
    ll right_sum = build_segment_tree(node * 2 + 1, mid + 1, end);
    
    return seg_tree[node] = left_sum + right_sum;
}

ll sum_query(int node, int start, int end, int left, int right) {
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) return seg_tree[node];

    int mid = (start + end) / 2;
    return sum_query(node * 2, start, mid, left, right) +
           sum_query(node * 2 + 1, mid + 1, end, left, right);
}

void update_segment_tree(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    
    seg_tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update_segment_tree(node * 2, start, mid, index, diff);
        update_segment_tree(node * 2 + 1, mid + 1, end, index, diff);
    }
}

void solution() {
    int tree_height = (int)ceil(log2(n));
    int tree_size = (1 << (tree_height + 1));
    seg_tree.resize(tree_size, 0);

    build_segment_tree(1, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {  // 값 변경
            int index;
            ll value;
            cin >> index >> value;
            index--;

            ll diff = value - arr[index];
            arr[index] = value;
            update_segment_tree(1, 0, n - 1, index, diff);
        } else {  // 구간 합
            int left, right;
            cin >> left >> right;
            cout << sum_query(1, 0, n - 1, left - 1, right - 1) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solution();

    return 0;
}
