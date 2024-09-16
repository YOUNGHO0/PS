#include <bits/stdc++.h>

using namespace std;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int number;

	cin >> number;

	vector<vector<int>> v;

	for(int i =0; i<number; i++){

		vector<int> temp;

		for(int j =0; j<4; j++){

			int option;
			cin >> option;
			temp.push_back(option);

		}
		v.push_back(temp);
		
	}

	sort(v.begin(),v.end(),[](vector<int> a, vector<int> b){

		int val1 = a[1] *a[2]*a[3];
		int val2 = b[1] *b[2]*b[3];
		if(val1 != val2){
			return val1<val2;
		}
		else{
			int val11 = a[1] +a[2]+a[3];
			int val22 = b[1] +b[2]+b[3];
			if(val11 != val22){
				return val11 < val22;
			}
			else{

				return a[0] <b[0];
			}
			
		}	
	});

	for(int i =0; i<3; i++){
		cout << v[i][0] << " "; 
	}
	cout << endl;

	return 0;
}