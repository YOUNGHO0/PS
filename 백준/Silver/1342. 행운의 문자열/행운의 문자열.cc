#include <bits/stdc++.h>
using namespace std;

string target;
bool checked[15] = {false};
vector<char> res;
int cnt = 0;
map<char,int> strMap;
void permutation(int val) {
    int flag = 0;
    if (res.size() == val) {
        // 인접 문자가 같은지 확인
        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i] == res[i + 1]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) cnt++; // 행운의 문자열인 경우에만 카운트
        return;
    }

   
   	for(auto &s : strMap){

   		if(!res.empty() && res.back() == s.first) continue;
		if(s.second <=0) continue;

		s.second--;
		res.push_back(s.first);
		permutation(val);
		res.pop_back();
		s.second++;

   	}

}

int main() {
    cin >> target;


    for(auto i : target){

    	strMap[i]++;
    }

   
    permutation(target.length());
    cout << cnt; // 중복 없는 행운의 문자열의 개수 출력
}
