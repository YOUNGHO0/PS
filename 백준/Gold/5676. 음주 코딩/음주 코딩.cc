#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

vector<int> arr;
int N, K;


int sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}


void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = sign(arr[start]);
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }
}


void update(int node, int start, int end, int pos, int value) {
    if (start == end) {
        tree[node] = sign(value);
    } else {
        int mid = (start + end) / 2;
        if (pos <= mid) {
            update(node * 2, start, mid, pos, value);
        } else {
            update(node * 2 + 1, mid + 1, end, pos, value);
        }
        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }
}


int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1; 
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    int left_result = query(node * 2, start, mid, left, right);
    int right_result = query(node * 2 + 1, mid + 1, end, left, right);
    return left_result * right_result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (cin >> N >> K) {
        arr.resize(N + 1);
        tree.resize(4 * N);
        
        
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        
        build(1, 1, N);

        
        string result;

        
        for (int i = 0; i < K; i++) {
            char cmd;
            int a, b;
            cin >> cmd >> a >> b;
            if (cmd == 'C') {
                update(1, 1, N, a, b);
            } else if (cmd == 'P') {
                int product = query(1, 1, N, a, b);
                if (product > 0) result += '+';
                else if (product < 0) result += '-';
                else result += '0';
            }
        }

        
        cout << result << '\n';
    }

    return 0;
}
