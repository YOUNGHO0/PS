#include <bits/stdc++.h>

using namespace std;

int main(){

    int num;
    cin >> num;
    long temp;
    vector<long> arr;
    for(int i = 0; i<num; i++){
        cin >> temp;
        arr.push_back(temp);
    }


    long min = LONG_MAX;
    long ans1;
    long ans2;
    long ans3;

    sort(arr.begin(), arr.end());

    for(int i = 0; i+2<arr.size(); i++){
        int left = i+1;
        int right = arr.size()-1;
        while(left < right){
            long sumArr= arr[i] + arr[right] + arr[left];
            if(abs(sumArr) < abs(min)){
                min = sumArr;
                ans1 = arr[i];
                ans2 = arr[left];
                ans3 = arr[right];
            }
            
            if( sumArr > 0){
                right--;
            }
            else if( sumArr < 0){
                left++;
            }
            else if(sumArr == 0)
            {
                break;
            }
        }
    }

    cout << ans1 << " " << ans2 << " " << ans3 << endl;


   
}