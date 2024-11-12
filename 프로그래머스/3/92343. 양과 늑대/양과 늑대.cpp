#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int maxSheep = 0;
    vector<int> dp(1 << info.size(), -1); // 각 상태를 초기화
    
    dp[1] = 1; // 루트(0번 노드)에서 시작, 양 한 마리
    
    for (int i = 1; i < (1 << info.size()); i++) { // 모든 상태 탐색
        if (dp[i] == -1) continue; // 유효하지 않은 상태는 건너뜀
        
        int sheep = 0, wolves = 0;
        
        // 현재 상태에서 양과 늑대 수를 세기
        for (int j = 0; j < info.size(); j++) {
            if (i & (1 << j)) { // i 상태에 포함된 노드라면
                if (info[j] == 0) sheep++;
                else wolves++;
            }
        }
        
        // 조건: 양의 수가 늑대 수보다 많을 때만 진행
        if (sheep <= wolves) continue;
        
        maxSheep = max(maxSheep, sheep); // 최대 양 수 갱신
        
        // 다음 상태로 이동
        for (auto edge : edges) {
            int parent = edge[0], child = edge[1];
            
            // i 상태에 부모 노드가 포함되고 자식 노드가 포함되지 않은 경우
            if ((i & (1 << parent)) && !(i & (1 << child))) {
                dp[i | (1 << child)] = max(dp[i | (1 << child)], dp[i] + (info[child] == 0 ? 1 : 0));
            }
        }
    }
    
    return maxSheep;
}
