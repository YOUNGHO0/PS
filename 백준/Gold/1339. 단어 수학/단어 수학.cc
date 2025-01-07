#include <bits/stdc++.h>


using namespace std;



vector<char> myVector;
int visited[12] = {0};
int ans[40] = {0};
vector<string> wordList;
int answer = INT_MIN;
void getPermutation(int curDepth,int depth){

 
    if(curDepth == depth){

        int total = 0;
        for(auto s : wordList){
            int number = 0;
            for(int i = 0; i<s.size(); i++){
                number *=10;
                number += ans[s[i] - 'A'];
            }

            total += number;

        }
        answer = max(answer,total);

    }
    else{
        for(int i =0; i<10; i++){
            if(visited[i]== 0){
                visited[i] = 1;
                ans[myVector[curDepth]-'A'] = i;
                getPermutation(curDepth+1,depth);
                visited[i] = 0;
                ans[myVector[curDepth]-'A'] = 0;
            }
        }
    }

}

int main(){

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int totalNum = 0;
    cin >> totalNum;
    int totalAlpha = 0;

    string temp;
    for(int i =0; i<totalNum; i++){
        cin >> temp;

        for(int j =0; j<temp.size(); j++){
            if(find(myVector.begin(), myVector.end(),temp[j]) == myVector.end()){
                myVector.push_back(temp[j]);
            }
        }

        wordList.push_back(temp);
    }

    getPermutation(0,myVector.size());
    cout << answer << endl;


      

}