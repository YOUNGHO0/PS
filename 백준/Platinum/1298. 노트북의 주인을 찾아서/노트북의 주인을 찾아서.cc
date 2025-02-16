#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> noteBookList;
int noteBookVisited[10004] = {0};
int visited[10004] = {0};

bool canUse(int personNumber) {
    for (int noteBookNumber : noteBookList[personNumber]) {

        if(visited[noteBookNumber] !=0) continue;

        visited[noteBookNumber] = 1;

        if(noteBookVisited[noteBookNumber] == 0 || canUse(noteBookVisited[noteBookNumber])){
            noteBookVisited[noteBookNumber] = personNumber;
            return true;
        }

    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int totalNumber, people;
    cin >> totalNumber >> people;

    for (int i = 0; i < people; i++) {
        int from, to;
        cin >> from >> to;
        noteBookList[from].push_back(to);
    }

    int ans = 0;
    for (int i = 1; i <= totalNumber; i++) {
       fill(visited, visited + totalNumber + 1, 0);  // 매칭 시도할 때마다 방문 배열 초기화
        if (canUse(i)) ans++;
    }

    cout << ans << endl;
    return 0;
}
