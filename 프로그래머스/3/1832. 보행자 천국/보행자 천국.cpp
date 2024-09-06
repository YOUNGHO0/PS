#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct info{
    int y,x,dir,val;
};
info tmp;
int MOD = 20170805;
int dx[2]={0,1};
int dy[2]={1,0};
int check[500][500][2];

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<2;k++)
                check[i][j][k]=0;
    queue<info> q;
    for(int i=0;i<2;i++){
        check[0][0][i]=1;
    }
    q.push({0,0,0,1});
    
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int cd = q.front().dir;
        int cv = q.front().val;
        q.pop();
        if(check[cy][cx][cd]!=cv) continue;
        if(cy==m-1 && cx==n-1){
            answer = (answer+cv)%MOD;
            continue;
        }
        int ca = city_map[cy][cx];
        if(ca==1) continue;
        for(int i=0;i<2;i++){
            if(ca==2 && cd!=i) continue;
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                check[ny][nx][i]=(check[ny][nx][i]+cv)%MOD;
                q.push({ny,nx,i,check[ny][nx][i]});
            }
        }
    }
    return answer;
}
