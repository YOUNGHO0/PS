    #include <bits/stdc++.h>
    using namespace std;
    int N,L,R;
    vector<vector<int>> visited;
    vector<vector<int>> arr;
    int total;
    int viscount =0;
    bool isUpdate = false;
    void printv(){

        for(int i =0; i<N; i++){
            for(int j =0; j<N; j++){
                cout << visited[i][j] << " ";
                }
                cout << endl;
        }
    }
     void print(){

        for(int i =0; i<N; i++){
            for(int j =0; j<N; j++){
                cout << arr[i][j] << " ";
                }
                cout << endl;
        }
    }



    void bfs(int y, int x){
        total = 0;
        int counter = 0;
        queue<pair<int,int>> bQueue;
        vector<pair<int,int>> ansVector;
        bQueue.push({y,x});
        visited[y][x] = viscount;
        while(!bQueue.empty()){
            counter++;
        auto[y,x] = bQueue.front();
        ansVector.push_back({y,x});
        total += arr[y][x];
        bQueue.pop();
        
        int dy[] ={1,-1,0,0};
        int dx[] = {0,0,1,-1};

        for(int i =0; i<4; i++){
            int ny = y + dy[i];
            int nx  = x + dx[i];

            if(ny <0 || nx <0 || ny>=N || nx>= N) continue;
            int imgae = abs(arr[ny][nx]- arr[y][x]);
            if(visited[ny][nx]== 0 && L<= imgae && imgae <= R ){
                visited[ny][nx] = viscount;
                bQueue.push({ny,nx});
            } 

        } 

        }
        int cnt = counter;
        int ans = total /cnt;
        for( auto [y,x] : ansVector){
            arr[y][x] = ans;
        }
    }

   




    int main(){

        cin >> N >> L >> R;
        arr.assign(N,vector(N,0));
        visited.assign(N,vector(N,0));

        for(int i =0; i<N; i++){
        
            for(int j =0; j<N; j++){
                cin >> arr[i][j];
            }
        }
        int cnt = 0;
        while(1){
            cnt++;
            visited.assign(N,vector(N,0));
            vector<vector<int>> cpy = arr;
            for(int i =0; i<N; i++){

                for(int j =0; j<N; j++){
                    if(visited[i][j] == 0){
                        viscount++;
                        bfs(i,j);
                    }
                }
            }
        int flag = 0;
        for(int i =0; i<N; i++){
            for(int j =0; j<N; j++){
                if(cpy[i][j] != arr[i][j])
                    flag = 1;
            }
        }

        if(flag == 0) break;
        }
        

        cout << cnt-1 <<endl;

        



        return 0;
    }