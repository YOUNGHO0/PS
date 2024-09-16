#include <bits/stdc++.h>


using namespace std;
vector<int> res;
bool visited[10] ={false};
int N;
void permutation(){

 	if(res.size() == N){

 		for(auto i : res){
 			cout << i << " ";
 		}
 		cout << endl;

 	}
 	else{

 		for(int i =1; i<=N; i++){
 			if(visited[i]) continue;
 			visited[i] = true;
 			res.push_back(i);
 			permutation();
 			res.pop_back();
 			visited[i] = false;

 		}
 	}



}

int main(){
ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

cin >> N;

permutation();

}