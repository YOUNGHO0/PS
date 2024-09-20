#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<vector<int>> res;
vector<int> arr;
vector<int> resVector;
int cnt  = 0;
void combi(int level, int target){


	if(resVector.size() == target){

		if(accumulate(resVector.begin(),resVector.end(),0) == S){
				cnt++;
		}
	}
	else{

		for(int i =level; i<N; i++){

		resVector.push_back(arr[i]);
		combi(i+1,target);
		resVector.pop_back();

		}
	}





}


int main(){



cin >> N >> S;


int num;
for(int i =0; i<N; i++){

 	cin >> num;
 	arr.push_back(num);
}

for(int i =0; i<N; i++){

	combi(0,i+1);
}

cout << cnt<<endl;




}