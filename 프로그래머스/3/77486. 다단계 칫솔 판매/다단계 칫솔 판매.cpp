#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    map<string,long> enrollMap;
    // 사람 이름과 얼만큼 받아갔는지 저장하는 갑을 가지는 map을 만든다.
    for (auto i : enroll){
        enrollMap.insert({i,0});
    }
    
    // referal과 enroll을 서로 연결한다.
    map<string,string> referralMap;
    
    
    for(int i = 0; i<referral.size(); i++){
        
        referralMap.insert({enroll[i],referral[i]});
        
    }
     // 모든 판매액에 대해서 "-" 을 만날 때 까지 판매액을 업데이트 시킨다.
    for(int i =0; i<seller.size(); i++){
        string person = seller[i];
        int output = amount[i]*100;
        while(person != "-"){
            // 절사하여 배분할 금액이 없다면 다 가지고 끝난다.
            if(output *0.1 == 0){
                enrollMap[person] += output;
                break;
            }
            else{
                // 배분할 때 원단위로 절사해서 남은 금액이 있으므로 해당 금액만큼을 빼고 자신이 가진다.
                int num = output * 0.1;
                enrollMap[person] +=output - num;
                output = num;
                person = referralMap[person];
            }
            
        }
    }

    
   //입력으로 주어진 enroll에 이름이 포함된 순서에 따라 나열한다.
 
    vector<int> answer;
    for(auto i: enroll){
        answer.push_back(enrollMap[i]);
    }
    return answer;
}