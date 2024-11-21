#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin >> num;
    long temp;
    vector<long> arr;
    
    // 배열 입력 받기
    for(int i = 0; i < num; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    long min = LONG_MAX; // 큰 값으로 초기화
    long ans1, ans2, ans3;

    // 배열 정렬
    sort(arr.begin(), arr.end());

    for(int i = 0; i + 2 < arr.size(); i++) {
        int left = i + 1;
        int right = arr.size() - 1;

        while(left < right) {
            long sumArr = arr[i] + arr[left] + arr[right];

            if(abs(sumArr) < abs(min)) { // 절대값이 더 작은 합을 찾으면
                min = sumArr; // min 갱신
                ans1 = arr[i];
                ans2 = arr[left];
                ans3 = arr[right];
            }

            // 합이 0보다 큰 경우 right를 줄이고, 작은 경우 left를 늘림
            if(sumArr > 0) {
                right--;
            } else if(sumArr < 0) {
                left++;
            } else {
                break; // sumArr가 0일 경우 더 이상 탐색할 필요 없음
            }
        }
    }

    // 결과 출력
    cout << ans1 << " " << ans2 << " " << ans3 << endl;

    return 0;
}
