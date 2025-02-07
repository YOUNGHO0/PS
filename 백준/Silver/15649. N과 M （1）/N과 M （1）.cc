#include <bits/stdc++.h>

using namespace std;

int visited[10] = {0};
int N,M;

void dfs(int count , vector<int> ans){

    if(count == M){
        for(auto i : ans) printf("%d ", i);
        printf("\n");
        return;
    }
    else{

        for(int i =1; i<=N; i++){
            if( visited[i] ==0){
                visited[i] = 1;
                ans.push_back(i);
                dfs(count+1,ans);
                ans.pop_back();
                visited[i] = 0;
            }
        }   
    }

} 


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >>N>>M;

    dfs(0,{});


    return 0;
}