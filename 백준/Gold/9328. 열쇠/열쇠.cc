#include<bits/stdc++.h>

using namespace std;

queue<pair<int,int>> bfsQueue;
vector<string> arr;
set<char> alphaSet;
int visited[102][102] = {0}; 
map<char,queue<pair<int,int>>> alphaMap;
int ans = 0;
void bfs(){

   
    while(!bfsQueue.empty()){

        auto [y,x] = bfsQueue.front();
        // cout << "y " << y << "x " << x << endl; 
        bfsQueue.pop();
        if('a'<=arr[y][x] && arr[y][x] <='z') {

            alphaSet.insert(arr[y][x]);
            queue<pair<int,int>> &t = alphaMap[arr[y][x]];
            while(!t.empty()){
                bfsQueue.push({t.front()});
                t.pop();
            }

      
        }
        else if('A' <=arr[y][x] && arr[y][x] <= 'Z'){

            int index = arr[y][x]- 'A';
            char lowerChar = 'a' + index;
            if(alphaSet.find(lowerChar) == alphaSet.end()){
                alphaMap[lowerChar].push({y,x});
                visited[y][x] =1;
                continue;
            }
        }
        else if(arr[y][x]== '$')ans++;


        int dy[] = {0,1,-1,0};
        int dx[] = {1,0,0,-1};

        for(int i =0; i<4; i++){

            int ny = y + dy[i];
            int nx = x + dx[i];

            if( ny <0 || nx <0 || ny>= arr.size() || nx>= arr[0].size()) continue;

            if(visited[ny][nx] != 0|| arr[ny][nx]== '*') continue;

            visited[ny][nx] = 1;
            bfsQueue.push({ny,nx}); 
    }

}

}


int main(){

    int testCase;
    cin >> testCase;

    while(testCase != 0){
        testCase--;
        ans = 0;
        arr.clear();
        fill(&visited[0][0],&visited[0][0] +102*102, 0);
        alphaMap.clear();
        alphaSet.clear();
        bfsQueue = queue<pair<int,int>>();
        int width;
        int height;

        cin >> width >> height;

        

        for(int i =0; i<width; i++){
            string temp;
            cin >> temp;
            arr.push_back(temp);
        }
        string keys;
        cin >> keys;
        for(auto key : keys){
            alphaSet.insert(key);
        }
        for(int i =0; i<arr[0].size(); i++){
            if(arr[0][i] != '*'){
                bfsQueue.push({0,i});
                visited[0][i] = 1;
            }
            if(arr[arr.size()-1][i] != '*'){
                bfsQueue.push({arr.size()-1,i});
                visited[arr.size()-1][i] = 1;
            }
        }

        for(int i =1; i<arr.size()-1; i++){
            if(arr[i][0] != '*'){
                bfsQueue.push({i,0});
                visited[i][0] = 1;
            }
            if(arr[i][arr[0].size()-1] != '*'){
                bfsQueue.push({i,arr[0].size()-1});
                visited[i][arr[0].size()-1] = 1;
            }
        }
        bfs();
        cout << ans << endl;
    }

    return 0;
}