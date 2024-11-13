#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<int> se1(sequence);
    vector<int> se2(sequence);
    
    int num = 1;
    for(int i =0; i< se1.size(); i++){
        se1[i] = se1[i] * num;
        num *= -1;
    }
    num = -1;
    for(int i =0; i<se2.size(); i++){
        se2[i] = se2[i] * num;
        num *= -1;
    }
    
    
    int left = 0;
    int right = 0;
    long long total = 0;
    long long sum = 0;
    while( right < se1.size()){
        sum += se1[right];
        total = max(sum,total);
        right++;
        while( sum < 0 && left<= right){
            if(left == right){
                break;
            }
            else if(left < right){
                sum -= se1[left];
                total = max(sum,total);
                left++;
            }
        }
        
    }
    
    left = 0;
    right = 0;
    sum = 0;
    
    while( right < se2.size()){
        sum += se2[right];
        total = max(sum,total);
        right++;
        while( sum < 0 && left<= right){
            if(left == right){
                break;
            }
            else if(left < right){
                sum -= se2[left];
                total = max(sum,total);
                left++;
            }
        }
        
    }
    
    
    return total;
}