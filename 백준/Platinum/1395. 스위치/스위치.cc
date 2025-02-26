#include <bits/stdc++.h>

using namespace std;
int MAX = 100000;
int N,M;
vector<int> tree(MAX*4);
vector<int> lazy(MAX*4);

void propagate(int node, int start ,int end){


    if(lazy[node]%2 == 1){
        tree[node] = (end - start +1) - tree[node];
       if (start != end) {  // 리프 노드가 아니면 자식에게 lazy 전파
            lazy[node * 2] ^= 1;
            lazy[node * 2 + 1] ^= 1;
        }

    }

    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right){

    propagate(node,start,end);

    if(right < start || end <left) return;
    if(left <= start && end <= right){

        lazy[node] ^= 1;
        propagate(node,start,end);
        return;
    }

    int mid = (start+ end)/2;
    update(node*2, start,mid,left,right);
    update(node*2+1,mid+1,end,left,right);
    tree[node] = tree[node*2]+ tree[node*2+1]; 
}

int query(int node,int start, int end,int left, int right){
    propagate(node, start,end);
    if(right<start || end <left) return 0;
    if(left <= start && end <=right) return tree[node];

    int mid = (start+end)/2;
    return query(node*2,start,mid,left,right)+ query(node*2+1,mid+1,end,left,right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    while (M--) {
        int O, Si, Ti;
        cin >> O >> Si >> Ti;
        if (O == 0) {
            update(1, 1, N, Si, Ti);
        } else { 
            cout << query(1, 1, N, Si, Ti) << "\n";
        }
    }

    return 0;
}
