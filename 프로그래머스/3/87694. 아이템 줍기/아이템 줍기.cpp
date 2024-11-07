#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int arr[101][101] = {0};
int visited[101][101] = {0};
    
void draw(int x1, int y1, int x2 , int y2){
    
    for(int i = x1*2; i<=x2*2 ; i++){
        if(arr[y1*2][i] == 0)arr[y1*2][i] = 1;
        if(arr[y2*2][i] == 0 )arr[y2*2][i] = 1;
    }
    
    for(int i =y1*2; i<=y2*2; i++){
        if(arr[i][x1*2] == 0)arr[i][x1*2] = 1;
        if(arr[i][x2*2] ==0) arr[i][x2*2]= 1;
    }
    for(int i = y1*2+1; i<= y2*2-1 ; i++){
        
        for(int j = x1*2+1; j<= x2*2-1; j++){
            arr[i][j] = 2;
        }
    }
    
}
void print(){
    
    for(int i =18; i>=0; i--){
        for(int j =0; j<20; j++){
            std::cout << arr[i][j];
        }
        std::cout  << std::endl;
    }
}

void print2(){
    
    for(int i =20; i>=0; i--){
        for(int j =0; j<20; j++){
            std::cout << visited[i][j];
        }
        std::cout  << std::endl;
    }
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for (auto i : rectangle){
        draw(i[0],i[1],i[2],i[3]);
    }
    
    queue<vector<int>> mqueue;
    
    mqueue.push({characterY*2,characterX*2,0});
    visited[characterY*2][characterX*2] = 1;
    
    while(!mqueue.empty()){
        
        auto p = mqueue.front();
        mqueue.pop();
        
        
        int y = p[0];
        int x = p[1];
        int cnt = p[2];
        
       // cout << "y " << y << "x " << x << endl;
        if (y == (itemY*2) && x == (itemX*2)){
          // print2();
            return cnt/2;
        } 
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        for(int i =0; i<4; i++){
            
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            
            if(ny<0 || nx <0 || ny>100 || nx>100) continue;
            if(visited[ny][nx] != 0) continue;
            if(arr[ny][nx] == 1 && visited[ny][nx] == 0){
                visited[ny][nx] = cnt+1;
                mqueue.push({ny,nx,cnt+1});
            }
           
        }
        
    }
    
    return answer;
}