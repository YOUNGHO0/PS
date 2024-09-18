#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> question;
int answer = 0;

void solve() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (i == j) continue;
            for (int k = 1; k < 10; k++) {
                if (i == k || j == k) continue;

                int valid = 1;

                for (const auto& q : question) {
                    int num = q[0];
                    int strike = q[1];
                    int ball = q[2];

                    int a = num / 100;
                    int b = (num % 100) / 10;
                    int c = num % 10;

                    int st = 0, ba = 0;

                    if (i == a) st++;
                    else if (i == b || i == c) ba++;

                    if (j == b) st++;
                    else if (j == a || j == c) ba++;

                    if (k == c) st++;
                    else if (k == a || k == b) ba++;

                    if (st != strike || ba != ball) {
                        valid = 0;
                        break;
                    }
                }

                if (valid) answer++;
            }
        }
    }
}

int main() {
    int num;
    cin >> num;

    question.resize(num);
    for (int i = 0; i < num; i++) {
        int number, strike, ball;
        cin >> number >> strike >> ball;
        question[i] = {number, strike, ball};
    }

    solve();
    cout << answer << endl;

    return 0;
}
