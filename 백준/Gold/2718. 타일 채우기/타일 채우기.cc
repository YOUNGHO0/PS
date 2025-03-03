#include <bits/stdc++.h>

using namespace std;

int main(){


    long long arr[1002];

    fill(arr,arr+1002,0);
    int testCase;
    cin >> testCase;

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 5;
    arr[3] = 11;



    for(int i =3; i<=1000; i++){

        arr[i] = ((arr[i-1] %2147483647) + (arr[i-2])%2147483647 *4);

        for(int j = i-3; j>=0; j--){
            if((i-j) %2 == 0){
                arr[i] += (3*arr[j]) %2147483647;
            }
            else{
                arr[i] += (2*(arr[j]) %2147483647);
            }
        }
    }



    int temp;
    for(int i =0; i<testCase; i++){

        cin>>temp;
        cout << arr[temp]<< endl;
    }


    
}