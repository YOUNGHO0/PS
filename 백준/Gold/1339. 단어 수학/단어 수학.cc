#include <bits/stdc++.h>


using namespace std;


int main(){


    int totalNumber;
    cin >> totalNumber;

    map<char,int> alphaMap;
    for(int i =0; i<totalNumber; i++){
        string temp;
        cin >> temp;
        int power =0;
        for(int j = temp.size()-1; j >=0; j--){
            alphaMap[temp[j]] += (1 * pow(10,power));
            power++;
        }
    }

    vector<int> result;
    for(auto i : alphaMap){
        result.push_back(i.second);
    }

    sort(result.begin(),result.end(),greater<int>());
    
    int num = 9;
    int answer  =0;

    for(auto i : result) {
        answer += num * i;
        num--;
    }      

    cout << answer;
}