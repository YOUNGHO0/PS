#include <bits/stdc++.h>


using namespace std;

int main(){


	int N;

	cin >> N;


	int arr[1005][3];
	fill(&arr[0][0], &arr[0][0]+ 1005*3,0);
	int color[1005][3];
	fill(&color[0][0], &color[0][0]+ 1005*3,0);
	int num;
	for(int i =2; i<=N+1; i++){

		for(int j =0; j<3; j++){
			cin >>num;
			color[i][j] = num;
		}
	}


	for(int i =2; i<=N+1; i++){
		arr[i][0] = min(arr[i-1][2],arr[i-1][1]) + color[i][0];
		arr[i][1] = min(arr[i-1][2], arr[i-1][0]) + color[i][1];
		arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + color[i][2];

	}

	int min_number = 888888888;

	for(int k =0; k<3; k++){
		if(arr[N+1][k] <min_number){
			min_number = arr[N+1][k];
		}
	}

	cout << min_number << endl;


	

}