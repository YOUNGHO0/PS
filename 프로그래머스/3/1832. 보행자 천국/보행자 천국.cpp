#include <bits/stdc++.h>
#include <vector>

using namespace std;
int dy[] = {1,0};
int dx[] = {0,1};
int MOD = 20170805;
int M,N;
int visited[501][501][2] ={0};
vector<vector<int>> arr;

int  bfs(int pos){

    for(int i =0; i<M; i++){
        for(int j =0; j<N; j++){
            for(int k =0; k<2; k++){
                visited[i][j][k] = 0;
            }
        }
    }
    
    
    queue<vector<int>> mQueue;
    
    mQueue.push({0,0,0,1});
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;
    int ans = 0;
    while(!mQueue.empty()){
        
        vector<int> temp = mQueue.front();
        mQueue.pop();

        int y = temp[0];
        int x = temp[1];
        int pos = temp[2];
        int val = temp[3];
        
        
        if(val != visited[y][x][pos]) continue;
        
        if(y == M-1 && x == N-1) 
        {
            ans = (ans+val)%MOD;
            continue;
        }
        
        if(arr[y][x] == 2){
            
            int ny = y + dy[pos];
            int nx = x + dx[pos];
            
            if(ny<0 || nx< 0 || ny>= M || nx>=N) continue;
            if(arr[ny][nx] == 1  )continue;
            visited[ny][nx][pos] = (visited[ny][nx][pos]  + val)%MOD;
            mQueue.push({ny,nx,pos,visited[ny][nx][pos]});
        }
        else if(arr[y][x] == 0){
        for(int i =0; i<2; i++){
            
            int ny = y+ dy[i];
            int nx = x+ dx[i];
            if(ny <0 || nx<0 || ny>=M || nx>=N) continue;
            if(arr[ny][nx] == 1) continue;
            visited[ny][nx][i] = (visited[ny][nx][i]  + val)%MOD;
            mQueue.push({ny,nx,i,visited[ny][nx][i]});    
        }    
        }
        
        
    }

    return ans;
    
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> ar) {
    int answer = 0;
    M = m;
    N = n;
    arr = ar;


    
    return bfs(0);
}