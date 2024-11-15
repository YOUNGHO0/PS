#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> combi;
vector<int> res;
int m;
int tot;
void make_combi(int number, int depth){
    
    if(depth == m){
        int sum = 0;
        
        if(number !=0)return;
        for(int i =0; i<depth; i++){
            sum += res[i];
        }
        if( sum != tot){
            cout  << tot << " " << endl;
        }
        combi.push_back(res);
        return;
    } 
    else{
        for(int i = 1; i<=number; i++){
            res.push_back(i);
            make_combi(number-i,depth+1);
            res.pop_back();
        }
    }
    
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 99999999;
  
    m = k;
    tot = n;
    make_combi(n,0);
    for( vector<int> re : combi){
        vector<int> list = re;
        int total = 0;
        priority_queue<int,vector<int>,greater<>> pq[6];
        // list[0] = 2;
        // list[1] = 1;
        // list[2] = 2;
        for(int i = 0; i<reqs.size(); i++){
            vector<int> req = reqs[i];
            int start = req[0];
            int duration = req[1];
            int type = req[2]-1;
            if(list[type] >0){
                // cout << "더하지 않음 "<< start << " " << duration << endl;
                list[type]--;
                pq[type].push(start+duration);
            }
            else if(list[type] == 0){
                int finisedTime = pq[type].top();
                pq[type].pop();
                if(finisedTime> start){
                    total += (finisedTime - start);
                    // cout << finisedTime << " " << start << " " << endl;
                    pq[type].push(finisedTime + duration);
                }
               else{
                   pq[type].push(start + duration);
               }
            }
            
        }
        answer = min(answer, total);
    }
    return answer;
}