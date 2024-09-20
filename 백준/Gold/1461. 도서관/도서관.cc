#include <bits/stdc++.h>

using namespace std;
int main(){

	int num,bookCount;
	cin >> num;
	cin >> bookCount;
 	vector<int> a;
 	vector<int> b;
 	int number;
	for(int i=0; i<num; i++){
		cin >> number;
		if(number >0){
			a.push_back(number);

		}
		else{
			b.push_back(number);
		}

	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),greater());



	int ans = 0;
	if(!a.empty()&& !b.empty()){
		if(a.back() > abs(b.back())){
			ans += a.back();
			// cout << ans << endl;
			for(int i =0; i<bookCount && !a.empty(); i++){
				a.pop_back();
			}
		}
		else{
			ans+=abs(b.back());
			// cout << ans <<endl;
			for(int i =0; i<bookCount && !b.empty(); i++){
				b.pop_back();
			}
		}

	}
	else{
		if(a.empty()){
			ans += abs(b.back());
			for(int i =0; i<bookCount && !b.empty(); i++){
				b.pop_back();
			}
		}
		else{
			ans += abs(a.back());
			for(int i =0; i<bookCount && !a.empty(); i++){
				a.pop_back();
			}
		}
	}
	

	while(!a.empty()){
		int result = a.back();
		// cout << result*2 << endl;
		ans += result*2;
		for(int i =0; i<bookCount && !a.empty(); i++){
			a.pop_back();
		}

	}

	while(!b.empty()){
		int result = abs(b.back());
		// cout << result*2 <<endl;
		ans+=result*2;
		for(int i =0; i<bookCount && !b.empty(); i++){
			b.pop_back();
		}
	}

	cout << ans<<endl;
	return 0;
}