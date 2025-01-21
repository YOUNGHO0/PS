#include <bits/stdc++.h>


using namespace std;
int main(){


    vector<vector<pair<int,int>>> blockList ={
        {{0,1},{0,2},{0,3}},
        {{0,1},{1,0},{1,1}}, // ㅁ 끝
        {{1,0},{2,0},{3,0}},  // - 자 끝
        {{1,0},{2,0},{2,1}}, 
        {{1,0},{0,1},{0,2}},
        {{0,1},{1,1},{2,1}},
        {{0,1},{0,2},{-1,2}},
        {{0,1},{-1,1},{-2,1}},
        {{0,1},{0,2},{1,2}},
        {{0,1},{1,0},{2,0}},
        {{1,0},{1,1},{1,2}}, // ㄴ자 끝
        {{1,0},{1,1},{2,1}},
        {{1,0},{-1,1},{0,1}},//
        {{0,1},{-1,1},{-1,2}},
        {{0,1},{1,1},{1,2}}, //z자 끝
        {{0,1},{-1,1},{1,1}},
        {{1,0},{2,0},{1,1}},
        {{0,1},{0,2},{-1,1}},
        {{0,1},{0,2},{1,1}}
    };


    int row, col;
    cin >> row >> col;
    int answerSum = INT_MIN;

    vector<vector<int>> arr(row,vector<int>(col,0));
    
    for(int i =0; i<row; i++){
        for(int j =0; j<col; j++){

            cin >> arr[i][j];
        }
    }


    for(int k =0; k<blockList.size(); k++){

        for(int i =0; i<row; i++){
            for(int j =0; j<col; j++){

                int sum = arr[i][j];
                for(auto p : blockList[k]){

                    int ny = i + p.first;
                    int nx = j + p.second;
                    if(ny <0 || ny>=row || nx<0 || nx>= col){
                        sum =  -1;
                        break;
                    }
                    sum += arr[ny][nx];
                }
                if(sum == -1) continue;
                answerSum = max(answerSum,sum);
            }
        }


    }

    cout << answerSum << endl;
    
 

}