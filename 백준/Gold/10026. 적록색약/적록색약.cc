#include <bits/stdc++.h>

using namespace std;


void bfs1( vector<string> arr, int y,int x,int visited[100][100]){

    queue<pair<int,int>> myQueue;

    myQueue.push({y,x});



    while(!myQueue.empty()){

        auto [y,x] = myQueue.front();
        myQueue.pop();

        int dx[] ={1,-1,0,0};
        int dy[] ={0,0,1,-1};


    for(int i =0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <0 || ny>= arr.size() || nx<0 || nx>= arr[0].size() || visited[ny][nx] == 1) continue;

        if(arr[ny][nx] != arr[y][x]) continue;
        visited[ny][nx] = 1;
        myQueue.push({ny,nx});

    }   


}
    



}


int calculate1(vector<string> arr){

    int visited[100][100] = {0};
    int regionCount = 0;
    for(int i =0; i< arr.size(); i++){

        for(int j =0; j<arr[0].size(); j++){

            if(visited[i][j] == 0){
                regionCount++;
                visited[i][j] = 1;
                bfs1(arr,i,j,visited);
            }
        }
    }

    return regionCount;


}

void bfs2( vector<string> arr, int y,int x,int visited[100][100]){



    queue<pair<int,int>> myQueue;

    myQueue.push({y,x});


    while(!myQueue.empty()){

        auto [y,x] = myQueue.front();
        myQueue.pop();

        int dx[] ={1,-1,0,0};
        int dy[] ={0,0,1,-1};


    for(int i =0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <0 || ny>= arr.size() || nx<0 || nx>= arr[0].size() || visited[ny][nx] == 1) continue;

        if(arr[y][x] == 'R' && arr[ny][nx]== 'B')  continue;
        if(arr[y][x] == 'G' && arr[ny][nx]== 'B') continue;
        if(arr[y][x] == 'B' && (arr[ny][nx] == 'R' || arr[ny][nx] == 'G' )) continue;
        visited[ny][nx] = 1;
        myQueue.push({ny,nx});

    }   


}
    






}


int calculate2(vector<string> arr){

    int visited[100][100] = {0};
    int regionCount = 0;
    for(int i =0; i< arr.size(); i++){

        for(int j =0; j<arr[0].size(); j++){

            if(visited[i][j] == 0){
                regionCount++;
                visited[i][j] = 1;
                bfs2(arr,i,j,visited);
            }
        }
    }

    return regionCount;


}




int main(){

    int row;
    cin >> row;

    vector<string> arr;

    for(int i =0; i<row; i++){

        string temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << calculate1(arr)<< " ";
    cout << calculate2(arr);





}