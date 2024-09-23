#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string deli){
    long long pos;
    vector<string> res;
    while((pos = input.find(deli)) != string::npos){
        string result = input.substr(0,pos);
        res.push_back(result);
        input.erase(0,pos+deli.length());
    }
    res.push_back(input);
    
    return res;
}

string changeNumToZin(int number, int bi){
    int mok = number;
    if(number == 0) return "0";
    vector<char> cvector;
    while(mok >0){
        int num = mok%bi;
        mok = mok/bi;
        cvector.push_back('0'+ num);
    }
    
    reverse(cvector.begin(),cvector.end());
    
    string s(cvector.begin(),cvector.end());
    return s;
    
}

int changeZintoNum(string zin, int bi){
    
    int res=0;
    int mul = 1;
    for(int i = zin.size()-1; i>=0; i--){
        
        res+= (zin[i]-'0')*mul;
        mul *=bi;
        
    }
    return res;

}

int calculate(string s, int bi){
    
    vector<string> t = split(s," ");
    
    if(t[1] == "+"){
     return changeZintoNum(t[0],bi)+ changeZintoNum(t[2],bi);
    }
    else{
    return changeZintoNum(t[0],bi) - changeZintoNum(t[2],bi);
    }
    
    
}

bool isSame(string s, int bi){
    
    vector<string> t = split(s," ");
    
    if(t[1] == "+"){
     if( changeNumToZin(changeZintoNum(t[0],bi)+ changeZintoNum(t[2],bi),bi) == t[4]) return true;
        
        return false;
    }
    else{
        
        if( changeNumToZin(changeZintoNum(t[0],bi)- changeZintoNum(t[2],bi),bi) == t[4]) return true;
        
        return false;
    }
    
    
}
vector<string> solution(vector<string> expressions) {
    
    vector<string> answer;
    // 2부터 9까지에 대해서
    // 진법을 숫자로 바꾸고 더하고 뺀 뒤 진법으로 바꾼다
    //일치하는 진법만 필터링한다.
    vector<int> avail;
    
    for(string s : expressions){
        
        for(int i =0; i<s.length(); i++){
        
            if(s[i]>='0' && s[i]<='9'){
                avail.push_back(s[i]-'0');
            }
            
        }
        
    }
    
    sort(avail.begin(),avail.end(),greater());
    int m = avail[0];
    avail.clear();
    for(int i = m+1; i<=9; i++){
        avail.push_back(i); 
    }
    
    vector<int> temp;
    for(auto i : avail){
        int flag = 0;
        for(auto s : expressions){
            if(s.find("X") != string::npos) continue;
            
            if(!isSame(s,i)){
                flag = 1;
            }
            
        }
        if(flag == 0)temp.push_back(i);
    }
    
    avail = vector(temp.begin(),temp.end());
    
    vector<string> tests;
    for(auto s : expressions){
        
        if(s.find("X") != string::npos){
            tests.push_back(s);
        }
    }
    
    for(auto t : tests){
        
        set<string> tmap;
        int flag = 0;
        for(auto i : avail){
            int n = calculate(t,i);
            tmap.insert(changeNumToZin(n,i));
        }
        
        if(tmap.size() != 1){

            vector<string> an = split(t,"X");
            answer.push_back(an[0]+ "?" + an[1]);
        }
        else{
            vector<string> an = split(t,"X");
        
            answer.push_back(an[0]+ *tmap.begin() + an[1]);
        }
    }
    
    
    
    return answer;
}