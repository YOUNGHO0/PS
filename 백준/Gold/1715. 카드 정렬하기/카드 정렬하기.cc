#include <bits/stdc++.h>


using namespace std;

int main(){

    int totalContainer = 0;
    int totalCardNum = 0;
    cin >> totalContainer;

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i =0; i<totalContainer; i++){
        int cardNum;
        cin >> cardNum;
        pq.push(cardNum);
        
    }

    if(pq.size() == 1){
      cout << "0" << endl;
      return 0;   
    }

    int answer = 0;
    while(pq.size() != 1 && !pq.empty()){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        answer+= num1+num2;
        pq.push(num1+num2);
    }
    cout << answer << endl;




    

}