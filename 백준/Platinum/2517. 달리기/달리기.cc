#include <bits/stdc++.h>

using namespace std;

int tree[500005] = {0};
int num;
int sum(int x){
    int ans = 0;
    while(x >0){
        ans+= tree[x];
        x -= (x & (-x));
    }
    return ans;
}

void update(int x, int value){

    while( x <= num){
        tree[x] += value;
        x += (x & (-x));
    }
}



int main(){


    cin >> num;
    vector<pair<int,int>> userList;
    int temp;
    for(int i =0; i<num; i++){
        cin >> temp;
        userList.push_back({temp,i+1});
    }
    auto cmp = [](pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    };
    auto cmp2 = [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    };
    sort(userList.begin(),userList.end(),cmp);

    for(int i =0; i<userList.size(); i++){
        userList[i].first = i+1;
    }

    sort(userList.begin(),userList.end(),cmp2);

    for(int i =0; i<userList.size(); i++){
        int rank = userList[i].first;
        cout << i+1 - sum(rank) << '\n'; 
        update(rank,1);
    }

    return 0;
}