#include <bits/stdc++.h>

using namespace std;

int ROW, COLUMN, SHARK_NUM;

class Shark {
public:
    Shark(): is_dummy(true) {}

    Shark(int speed, int vect, int size)
    : speed(speed), vect(vect), size(size), is_dummy(false) {}

    bool is_dummy; // 상어가 있는지 여부
    int speed;     // 상어의 속도
    int vect;      // 상어의 방향 (1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽)
    int size;      // 상어의 크기
};

// 상어 이동 함수
void moveSharks(Shark arr[100][100]) {
    Shark temp[100][100]; // 이동 후 결과를 저장할 배열


    for(int i =0; i<ROW; i++){
        for(int j =0; j<COLUMN; j++){

            int y = i;
            int x = j;

            if(arr[y][x].is_dummy) continue;

            Shark s = arr[y][x];

            if(s.vect == 1){
                 y -= s.speed;
                 if(y <0){
                    y = -y;
                    s.vect = 2;
                 }

                 if(y>= ROW){
                    int mok = y/(ROW-1);
                    int nmg = y%(ROW-1);
                    if(mok %2 ==0){
                        y = nmg;
                    }
                    else{
                        s.vect = 1;
                        y = ROW-1 -nmg;
                    }
                 }

            }
            else if(s.vect == 2){

                y += s.speed;

                if(y>= ROW){
                    int mok = y/(ROW-1);
                    int nmg = y%(ROW-1);
                    if(mok %2 ==0){
                        y = nmg;
                    }
                    else{
                        s.vect = 1;
                        y = ROW-1 -nmg;
                    }
                 }

            }
            else if(s.vect == 4){

                x = x- s.speed;
                if(x<0){
                    x = -x;
                    s.vect = 3;
                }

                if(x >= COLUMN){
                    int mok = x/(COLUMN-1);
                    int nmg = x%(COLUMN-1);

                    if(mok %2 == 0){
                        x = nmg;
                    }
                    else{
                        x = COLUMN-1-nmg;
                        s.vect = 4;
                    }
                }

            }
            else if(s.vect == 3){
                x = x + s.speed;
                if(x >= COLUMN){
                    int mok = x/(COLUMN-1);
                    int nmg = x%(COLUMN-1);

                    if(mok %2 == 0){
                        x = nmg;
                    }
                    else{
                        x = COLUMN-1-nmg;
                        s.vect = 4;
                    }
                }

            }

            if(!temp[y][x].is_dummy){
                if(temp[y][x].size < s.size){
                    temp[y][x] = s;
                }
            }
            else{
                temp[y][x] = s;
            }

        }
    }


    for(int i =0; i<ROW; i++){
        for(int j =0; j<COLUMN;j++){
            arr[i][j] = temp[i][j];
        }
    }


}

// 낚시왕이 상어를 잡는 함수
int catchShark(Shark arr[100][100],int c) {
    for (int i = 0; i < ROW; i++) {
        if (!arr[i][c].is_dummy) {
            int caught_size = arr[i][c].size;
            arr[i][c] = Shark(); // 상어를 잡으면 해당 칸을 비워준다.
            return caught_size; // 잡은 상어의 크기 반환
        }
    }
    return 0; // 상어가 없다면 0 반환
}

int main() {
    cin >> ROW >> COLUMN >> SHARK_NUM;

    Shark arr[100][100]; // 격자판 (상어 위치 및 정보 저장)

    // 상어 정보 입력
    for (int i = 0; i < SHARK_NUM; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r--; c--; // 입력은 1-based 이므로 0-based로 변환
        arr[r][c] = Shark(s, d, z);

    }



    int total_size = 0; // 낚시왕이 잡은 상어 크기의 합

    // 낚시왕이 오른쪽으로 이동하며 상어를 잡는 시뮬레이션
    for (int t = 0; t < COLUMN; t++) {
        // 1. 낚시왕이 상어를 잡음
        total_size += catchShark(arr,t);

        // 2. 상어들이 이동함
        moveSharks(arr);
    }

    cout << total_size << endl;

    return 0;
}
