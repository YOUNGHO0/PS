#include <bits/stdc++.h>

using namespace std;

map<int,vector<pair<int,int>>> graph;

void dij(vector<vector<int>> & ans){

    priority_queue<tuple<int, bool, int>, vector<tuple<int, bool, int>> , greater<tuple<int,bool,int>>> myQueue;
    myQueue.push({0,true,1});
    while(!myQueue.empty()){

        auto [value,fast,node] = myQueue.top();
        myQueue.pop();

        if(fast){
            if(ans[node][1] < value) continue;
        }
        else {
            if(ans[node][0] <value) continue;
        }

        vector<pair<int,int>> adj = graph[node];
        for(auto i : adj){

            if(fast){

                if(ans[i.first][0] > value +(i.second ) ){
                ans[i.first][0] =  value +(i.second);
                myQueue.push({value +(i.second),!fast,i.first});
              }
            }
            else{

                if(ans[i.first][1] > value +(i.second *4) ){
                ans[i.first][1] =  value +(i.second *4);
                myQueue.push({value +(i.second *4 ),!fast,i.first});
            }

            
        }   

    }


    }
}


void dij2(vector<int> & ans){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> myQueue;
    myQueue.push({0,1});
    while(!myQueue.empty()){

        auto [value,node] = myQueue.top();
        myQueue.pop();

        vector<pair<int,int>> adj = graph[node];

        for(auto i : adj){
            if(ans[i.first] > value +(i.second*2)){
                ans[i.first] =  value +(i.second*2);
                myQueue.push({value +(i.second*2),i.first});
            }
        }

    }


}




int main(){

ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int N, E;
    cin >> N >> E;


    for(int i =0; i<E; i++){
        int from,to,val;
        cin >> from >> to >> val;
        graph[from].push_back({to,val});
        graph[to].push_back({from,val});

   
    }
        vector<vector<int>> answer1(N+1,vector<int>(2,INT_MAX));
        vector<int> answer2(N+1,INT_MAX);

        dij(answer1);
        dij2(answer2);
        answer2[1]= 0; 
        answer1[1][0] =0;
        answer1[1][1] = 0;

        int count = 0;
        for(int i = 2; i<=N; i++){
            if(answer2[i] < min(answer1[i][0],answer1[i][1]))
                count++;
        }
        cout << count << endl;

}