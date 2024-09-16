
#include <bits/stdc++.h>


using namespace std;

vector<vector<int>>resVector;
vector<int> res;
vector<int> arr;
void combi(int index){

	if(res.size() == 6){
		resVector.push_back(res);
	}
	else{

		for( int i =index+1; i<arr.size(); i++){
			res.push_back(arr[i]);
			combi(i);
			res.pop_back();
		}
	}


}

int main(){

	string line;
      
	int number;


	while(true){
		arr.assign(0,0);
		res.assign(0,0);
		resVector.assign(0,vector(0,0));
		std::getline(std::cin, line);
        
        // 입력된 줄을 스트림으로 변환하여 숫자를 처리
        std::stringstream ss(line);
        std::vector<int> numbers;
        int num;
        
        // 첫 번째 숫자 처리
        ss >> num;
        
        // 0이 입력되면 종료
        if (num == 0) {
            break;
        }
        // 나머지 숫자들을 벡터에 저장
        while (ss >> num) {
            arr.push_back(num);
        }
        combi(-1);

        sort(resVector.begin(),resVector.end());

        for(auto i : resVector){
        	for(auto j : i) 
        		cout << j << " ";
        	cout << endl;
        }


        cout << endl;
        
        
	}


}