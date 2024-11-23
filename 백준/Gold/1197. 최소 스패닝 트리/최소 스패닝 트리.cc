#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int parent[10002] = {0};

int find( int a){
    if(parent[a] !=a){
        parent[a] = find(parent[a]);
    }
    return parent[a];
}


void unionNumber(int a, int b){

    int pa = find(a);
    int pb = find(b);
    parent[pb] = pa;
}



class Edge{

public:

    Edge(int from,int to, long value):from(from),to(to),value(value){

    }

    int from;
    int to;
    long value;


};

int main(){

    int nodeNum;
    int edgeNum;
    cin >> nodeNum;
    cin >> edgeNum;

    auto cmp = [](Edge a, Edge b){

        return a.value > b.value;
    };
    priority_queue<Edge,vector<Edge>,decltype(cmp)> pq(cmp);

    int from;
    int to;
    long value;
    for(int i =0; i<edgeNum; i++){
        cin >> from >> to >> value;
        Edge e(from,to,value);
        pq.push(e);
    }

    
    for(int i =0; i<10002; i++){
        parent[i] = i;
    }

    long answer=0;

    while(!pq.empty()){
        Edge temp = pq.top();
        pq.pop();

        if(find(parent[temp.from]) != find(parent[temp.to])){
            unionNumber(temp.from,temp.to);
            answer+=temp.value;
        }
        
    }

    cout << answer << endl;

    
  





    return 0;
}
