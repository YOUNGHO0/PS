#include <bits/stdc++.h>


using namespace std;

int main(){

     vector<string> arr;
     int N;
     cin >> N;

     string temp;
     for(int i =0; i<N; i++){
        cin >> temp;
        arr.push_back(temp);
     }


     int ans = INT_MAX;
     for(int i =0; i<(1<<N); i++){
        vector<string> target = arr;
        for(int j =0; j<N; j++){
            if((i& (1<<j)) != 0){
                for(int k = 0; k<N; k++){
                    if(target[k][j] == 'H'){
                        target[k][j] = 'T'; 
                    }
                    else{
                        target[k][j] = 'H';
                    }
                }
            } 
        }

         int answer = 0;
            for(int k =0; k<N; k++){
                int tCount = 0;
                int hCount = 0;
                for(int s = 0; s<N; s++){
                    if(target[k][s]=='H'){
                        hCount++;
                    }
                    else{
                        tCount++;
                    }
                }
                if(tCount> hCount){
                    answer+= hCount;
                }
                else{
                    answer+= tCount;
                }
            }
            ans = min(ans,answer);
  

     }
     cout << ans <<endl;

    return 0;
}