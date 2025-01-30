#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[10003];
    int num;
    int answer = 0;
    cin >> num;

    for(int i =1; i<=num; i++){
        cin >> arr[i];
    }

    for(int i = 1; i<=num; i++){

        if(arr[i+1] > arr[i+2]){

            int count = min(arr[i], arr[i+1] - arr[i+2]);
            answer += 5* count;
            arr[i] -=count;
            arr[i+1] -= count;

            int count2 = min(arr[i],min(arr[i+1], arr[i+2]));
            answer += 7*count2;
            arr[i] -= count2;
            arr[i+1]-= count2;
            arr[i+2] -= count2;

        }
        else{
            int count = min(arr[i], min(arr[i+1], arr[i+2]));
            answer += 7*count;
            arr[i]-= count;
            arr[i+1]-=count;
            arr[i+2] -= count;

            int count2 = min(arr[i], arr[i+1]);

            answer+= 5*count2;
            arr[i] -= count2;
            arr[i+1]-=count2;
        }

        answer += 3*arr[i];
        arr[i] = 0;
    }

    cout << answer << endl;

    return 0;
}