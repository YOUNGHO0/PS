#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vt;
int solution(vector<vector<int>> scores) {
    
    for(int i =0; i<scores.size(); i++){
        scores[i].push_back(i);
    }
    sort(scores.begin(),scores.end(),[](vt a, vt b){
        return a[0]> b[0];

    });
    
    priority_queue<int,vector<int>,less<>> pq;
    vector<vector<int>> ans;
    int number = scores[0][0];
    stack<int> st;
    for(int i =0; i<scores.size(); i++){

        if(scores[i][0] != number){
            number = scores[i][0];
            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }
        }
        
        if(!pq.empty()){
            if(scores[i][1] >= pq.top()){
                ans.push_back(scores[i]);
                st.push(scores[i][1]);
            }
        }
        else{
             ans.push_back(scores[i]);
            pq.push(scores[i][1]);
        }
        
    }
    
    sort(ans.begin(),ans.end(), [](vt a, vt b){
        return a[0] + a[1] > b[0] + b[1];
    });
    
    int sum = ans[0][0] + ans[0][1];
    int rank = 1;
    for(int i =0; i<ans.size(); i++){
        if(sum != ans[i][0] + ans[i][1]){
            rank = i+1;
            sum = ans[i][0] + ans[i][1];
        }
        if(ans[i][2] == 0) return rank;
    
       
    }    
    return -1;
}