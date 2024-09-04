#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
    // 사전순으로 정렬
    sort(words.begin(), words.end());
    int answer = 0;

    for (int i = 0; i < words.size(); i++) {
        int prefix_length = 0;

        // 이전 단어와 비교
        if (i > 0) {
            // 두 단어 간의 공통 접두사 길이 계산
            int j = 0;
            while (j < words[i].size() && j < words[i - 1].size() && words[i][j] == words[i - 1][j]) {
                j++;
            }
            // 최대 길이 업데이트
            prefix_length = max(prefix_length, j + 1);
        }

        // 다음 단어와 비교
        if (i < words.size() - 1) {
            // 두 단어 간의 공통 접두사 길이 계산
            int j = 0;
            while (j < words[i].size() && j < words[i + 1].size() && words[i][j] == words[i + 1][j]) {
                j++;
            }
            // 최대 길이 업데이트
            prefix_length = max(prefix_length, j + 1);
        }

        // 최종적으로 해당 단어를 구분하는 데 필요한 글자 수를 더함
        answer += min(prefix_length, (int)words[i].size());
        
    }

    return answer;
}
