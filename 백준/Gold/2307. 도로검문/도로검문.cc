#include <bits/stdc++.h>


using namespace std;

map<int,set<pair<int,int>>> graph;
int N , M;

 
void dij(vector<int> & ans){


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0,1});

    while(!pq.empty()){


        auto [value,nodeNum] = pq.top();
        pq.pop();

        if(ans[nodeNum] < value) continue; //최적화를 위해 아마 필요

        for(auto [to,nodeVal] : graph[nodeNum]){


            if(value + nodeVal < ans[to]){
                ans[to]= value + nodeVal;
                pq.push({value+nodeVal,to});
            }
        }

    }
 

}


int main(){

    cin >> N >> M;

    int from, to, value;
    vector<vector<int>> test;
    
    for(int i =0; i<M; i++){

        cin >> from >> to >> value;
        graph[from].insert({to,value});
        graph[to].insert({from,value});

        test.push_back({from,to, value});

    }

     int maxNum = INT_MIN;
    int minNum = INT_MAX;

     vector<int> ori(N+1,INT_MAX);
     dij(ori);

     minNum = min(minNum,ori[N]);
     if(minNum == INT_MAX)  {

        cout << -1 << endl;
        return 0;
    }

    vector<bool> isPath(M+1,false);

    for(int i = 0; i<M; i++){
        int from = test[i][0];
        int to = test[i][1];
        int val = test[i][2];

        if(ori[from] + val == ori[to] || ori[to] + val == ori[from]){
            isPath[i] = true;
        }

    }



   
    for(int i =0; i<M; i++){
        vector<int> ans(N+1,INT_MAX);

        if(!isPath[i]) continue;
        graph[test[i][0]].erase({test[i][1],test[i][2]});
        graph[test[i][1]].erase({test[i][0],test[i][2]});

        dij(ans);
        // cout << test[i][1] << " " << test[i][0] << " " << test[i][2]<< endl;

        maxNum = max(maxNum,ans[N]);
        minNum = min(minNum,ans[N]);
        // cout << maxNum << endl;
        // cout << minNum << endl;

        graph[test[i][0]].insert({test[i][1],test[i][2]});
        graph[test[i][1]].insert({test[i][0],test[i][2]});

    }

    if(maxNum == INT_MAX) cout << -1 << endl;
    else{
        cout << maxNum - minNum << endl;
     
    }
        
}


