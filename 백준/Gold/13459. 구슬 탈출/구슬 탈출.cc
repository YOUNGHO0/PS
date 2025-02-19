#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

vector<string> arr;

pair<int,int> movePos(pair<int,int> point, int dy, int dx){


     int ny = point.first;
     int nx = point.second;

    while(1){
        ny +=dy;
        nx +=dx;


        if(ny<0 || nx <0 || ny>=arr.size() || nx>=arr[0].size()) break;

        if(arr[ny][nx] != '.'){ // 구멍이거나 벽이거나 다른 구슬이거나
 
             if(arr[ny][nx] == 'O'){
            arr[ny-dy][nx-dx] = '.';
            ny+= dy;
            nx+= dx;
            break;
            }

            break;
        }

        // 올바르게 움직인 경우
        auto temp =arr[ny-dy][nx-dx];
        arr[ny-dy][nx-dx]= arr[ny][nx];
        arr[ny][nx] = temp;
        

       

    }
    ny-=dy;
    nx-=dx;
    return {ny,nx};

}

void dfs(int count , pair<int,int> blue , pair<int,int> red){

    vector<string> temp = arr;
    if(count >10) {
        return;
    }

    if(arr[blue.first][blue.second] == 'O'){
        return;
    }
    else{

         if(arr[red.first][red.second] == 'O'){
   
        ans = min(ans,count);
        return;
        }
    }


        for(int i =0; i<4;i++){
          
        int dy[] = {1,-1,0,0};
        int dx[] = {0,0,-1,1};

        pair<int,int> newRedPos = movePos(red,dy[i],dx[i]);
        pair<int,int> newBluePos = movePos(blue,dy[i],dx[i]);
        if(arr[newRedPos.first][newRedPos.second] !='O')
        newRedPos = movePos(newRedPos,dy[i],dx[i]);
        
        if(newRedPos != red || newBluePos != blue){
            dfs(count+1,newBluePos, newRedPos);
        } 

        arr = temp;

    }
          



}


int main(){

    //. 빈칸  # 장애물 벽 0 구멍 위치 

    int N,M;

    cin >> N >> M;


    string temp;
    for(int i =0; i<N; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    pair<int,int> red;
    pair<int,int> blue;
    for(int i =0; i<arr.size(); i++){
        for(int j =0; j<arr[i].size(); j++){
            if(arr[i][j] == 'R'){
                red = {i,j};
            }
            if(arr[i][j] == 'B'){
                blue = {i,j};
            }
        }
    }
    // ㅜ ㅓ ㅗ ㅏ ㅜ ㅓ ㅜ
    dfs(0,blue,red );


    if(ans !=INT_MAX)
    cout << 1<<endl;
    else cout<< 0 << endl;

    return 0;
}