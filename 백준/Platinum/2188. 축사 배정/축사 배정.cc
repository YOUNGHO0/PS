#include <bits/stdc++.h>

using namespace std;

int check[201];  // 방문 여부 확인
vector<vector<int>> cowChukList(201, vector<int>(0, 0));  // 각 소가 원하는 축사 목록
vector<int> fromTo(201, -1);  // 소 -> 축사 매칭 정보
vector<int> toFrom(201, -1);  // 축사 -> 소 매칭 정보

bool dfs(int start) {
    if (check[start]) return false;
    check[start] = true;

    for (int i = 0; i < cowChukList[start].size(); i++) {
        int x = cowChukList[start][i];  // 소가 원하는 축사 번호
        if (toFrom[x] == -1 || dfs(toFrom[x])) {
            // 축사가 비어 있거나, 기존 매칭된 소를 다른 축사로 이동 가능
            toFrom[x] = start;
            fromTo[start] = x;
            return true;
        }
    }
    return false;
}

int main() {
    int cowCount, chukCount;
    cin >> cowCount >> chukCount;

    for (int i = 1; i <= cowCount; i++) {
        int number;
        cin >> number;  // 각 소가 원하는 축사의 수
        for (int j = 0; j < number; j++) {
            int chuk;
            cin >> chuk;
            cowChukList[i].push_back(chuk);
        }
    }

    int size = 0;  // 매칭된 소의 수
    for (int i = 1; i <= cowCount; i++) {
        memset(check, 0, sizeof(check));  // 방문 여부 초기화
        if (dfs(i)) size++;  // 매칭 성공 시 크기 증가
    }

    cout << size << endl;  // 최댓값 출력
    return 0;
}
