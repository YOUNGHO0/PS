#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sticker)
{
    
    if(sticker.size() == 1){
        return sticker[0];
    }
    else if(sticker.size() == 2){
        return max(sticker[0],sticker[1]);
    }
    
    int arr[100002][2] = {0};
    
    arr[0][0] = sticker[0];
    arr[0][1] = 0;
    
    arr[1][0] = arr[0][0];
    arr[1][1] = sticker[1];
    
    for(int i =2; i<sticker.size(); i++){
        
        arr[i][0] = max(arr[i-1][0], arr[i-2][0] + sticker[i]);
        arr[i][1] = max(arr[i-1][1], arr[i-2][1] + sticker[i]);
    }
    
    
    
    return max(arr[sticker.size()-2][0], arr[sticker.size()-1][1]);

}