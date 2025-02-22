#include <bits/stdc++.h>


using namespace std;
vector<int> arr;


class SegmentTree{

public:

    vector<int> tree;

    SegmentTree(int number){

       tree.resize(4 * number, INT_MAX); 

    }

int build(int treeNumber, int start, int end) {
    if (start == end) {
        return tree[treeNumber] = arr[start];  // ✅ 리턴값 명확히 설정
    }

    int mid = (start + end) / 2;
    int leftMin = build(treeNumber * 2, start, mid);
    int rightMin = build(treeNumber * 2 + 1, mid + 1, end);

    return tree[treeNumber] = min(leftMin, rightMin);  // ✅ 올바르게 동작
}


    int query (int treeNumber, int start, int end, int queryStart, int queryEnd){

        if( queryEnd<start || end < queryStart) return INT_MAX;

        if(queryStart <= start && end <= queryEnd){
            return tree[treeNumber];
        }
        else{
            int mid = (start + end)/2;
            int ans = min(query(treeNumber*2,start,mid,queryStart,queryEnd), query(treeNumber*2+1,mid+1,end,queryStart,queryEnd));
            return ans;
        }

    }


};









int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int nodeCount, queryCount;

    cin >> nodeCount>> queryCount;

    SegmentTree t(nodeCount);
    int temp;
    for(int i =0; i<nodeCount; i++){
        cin >> temp;
        arr.push_back(temp);

    } 
    t.build(1,0,arr.size()-1);
    int from,to;
    for(int i =0; i<queryCount; i++){

        cin >> from >> to;
        cout << t.query(1,0,arr.size()-1,from-1,to-1) << '\n';
    }



    return 0;
}