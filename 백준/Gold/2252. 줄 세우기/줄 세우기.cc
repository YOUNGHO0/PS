#include <bits/stdc++.h>

using namespace std;

vector<int> answer;
map<int,vector<int>> graphList;


int main(){

    int studentCount = 0;
    int numberOfRow = 0;
    

    cin >> studentCount;
    cin >> numberOfRow;
    vector<int> inNodes(studentCount+1,0);
    for(int i =0; i<numberOfRow; i++){
    
    int from,to;
    cin >> to >> from;
    inNodes[to]++;
    graphList[from].push_back(to);
    }

    int flag = 0;
    queue<int> myQueue;
    for(int i =1; i<= studentCount; i++){
        if(inNodes[i] == 0){
            myQueue.push(i);
        }
    }



    while(!myQueue.empty()){

        int num = myQueue.front();
        myQueue.pop();
        answer.push_back(num);
        auto list = graphList[num];
        for(int j =0; j<list.size(); j++){
            int to = list[j];
            inNodes[to]--;
            if(inNodes[to]== 0){
              myQueue.push(to);  
              inNodes[to] = -1;
            } 
            
        }

    }

    reverse(answer.begin(),answer.end());
    for(auto i : answer){
        cout << i << " ";
    }


}