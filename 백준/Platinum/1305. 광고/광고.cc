#include <bits/stdc++.h>

using namespace std;

vector<int> computeLsp(string input){

    int s = input.size();
    vector<int> output(s,0);

    int i = 1;
    int length = 0;
    while( i< s){

        if(input[i] == input[length]){
            length++;
            output[i] = length;
            i++;
        }
        else{
            if(length !=0){
            length = output[length-1];    
            }
            else{
                output[i] = 0;
                i++;
            }   
        }
    }

    return output;
}

void kmpSearch(string & pattern , string & text , vector<int> lsp){


    int textPtr = 0;
    int patternPtr = 0;

    while(textPtr<text.size()){

        if(pattern[patternPtr]== text[textPtr]){
            patternPtr++;
            textPtr++;
        }
        else{
            
            if(patternPtr != 0){
                patternPtr = lsp[patternPtr-1];
            }
            else{
                textPtr++;
            }
        }

        if(patternPtr == pattern.size()){
            cout << "foundpattern in" << " " << textPtr -patternPtr <<endl;
            patternPtr = lsp[patternPtr - 1];
            
        }
        

    }


}



int main(){

    int L;
    string s;
    
    // 입력 받기
    cin >> L;
    cin >> s;
    
    // LPS 배열 계산
    vector<int> lps = computeLsp(s);
    
    // 최소 광고의 길이는 L - lps[L-1] (LPS 값은 0부터 시작하므로)
    int min_ad_length = L - lps[L-1];
    
    // 결과 출력
    cout << min_ad_length << endl;


}