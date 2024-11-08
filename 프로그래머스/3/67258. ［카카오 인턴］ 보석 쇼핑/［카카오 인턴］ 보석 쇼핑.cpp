#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {

    //전체 보석 집합
    set<string> gemsSet(gems.begin(),gems.end());
    
    int left = 0;
    int right = 0;
       

    // 보석들을 담으면서 확인할 map
    map<string,int> ans;
    
    // 정답들을 담을 벡터
    vector<vector<int>> ansVector;
    
    //right로 끝까지 확인하면서
    for(int right = 0; right < gems.size(); right++){
        
        //right의 보석값을 담고
        ans[gems[right]]++;
        
        //정답이라는 가정하에 left가 right를 넘지 않는 선에서 반복하면서 정답을 찾아내는데
        while(ans.size() == gemsSet.size() && left <=right){
            // 우선 정답은 맞으니 넣고
            ansVector.push_back({left+1,right+1});
            // left 가 right 보다 작으면 한번 더 돌릴 수 있고
            if(left < right){
                ans[gems[left]]--;
                if(ans[gems[left]] == 0) ans.erase(gems[left]);
                left++;
            }
            // 그렇지 않으면 여기서 만족해야 한다.
            else if(left == right){ break;}
            
            
        }
    }
    
    
    // 정답 조건에 맞추어 정렬한뒤
    sort(ansVector.begin(), ansVector.end(), [](auto a, auto b){
        int left =  a[1] - a[0];  
        int right = b[1] - b[0];
        
        if(left != right) return left < right;
        else{
            return a[0] < b[0];
        }
    });
    

    // 정답을 리턴한다.    
    return ansVector[0];
}