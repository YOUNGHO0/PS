#include <bits/stdc++.h>
using namespace std;
vector<long long> calWeigtOnCombi(int start, int end, vector<long long>& weight) {
    vector<long long> res;
    int size = end - start;
    for (int i = 0; i < (1 << size); i++) {
        long long sum = 0;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                sum += weight[start + j];
            }
        }
        res.push_back(sum);
    }
    return res;
}



int main(){


    int N;
    int C;

    cin >> N;
    cin >> C;
    vector<long long> arr;
    long long  temp;
    for(int i =0; i<N; i++){

        cin >> temp;
        arr.push_back(temp);
    }

    auto left = calWeigtOnCombi(0,N/2,arr);
    auto right = calWeigtOnCombi(N/2,N,arr);

    sort(right.begin(), right.end());
    long long  answer = 0;

    for(auto l : left){
        long long count  = upper_bound(right.begin(),right.end(), C-l) - right.begin();
        answer+= count;
    }

    cout << answer << endl;
    return 0;
}