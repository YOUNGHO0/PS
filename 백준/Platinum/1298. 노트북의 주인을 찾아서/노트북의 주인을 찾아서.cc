#include <bits/stdc++.h>

using namespace std;

map<int,vector<int>> noteBookList;

int noteBookVisited[10004] = {0};
int visited[10004] = {0};
bool canUse(int personNumber){


    vector<int> noteList = noteBookList[personNumber];

    for(auto noteBookNumber : noteList){

        if(visited[noteBookNumber] !=0 )continue;
        visited[noteBookNumber] =1;


        if(noteBookVisited[noteBookNumber] ==0){
            noteBookVisited[noteBookNumber] = personNumber;
            return true; 
        }
        else if(noteBookVisited[noteBookNumber] != 0){
            int alreadyPersoNumber = noteBookVisited[noteBookNumber];
            if( canUse(alreadyPersoNumber)){
                noteBookVisited[noteBookNumber] = personNumber;
                return true; 
            }

        }

    }
    return false;

}




int main(){

    int totalNumber, people;

    cin >> totalNumber >> people;

    for(int i =0; i<people; i++){

        int from, to;
        cin >> from >> to;
        noteBookList[from].push_back(to);
    }
    int ans = 0;
    for(int i =1; i<=totalNumber; i++){
        memset(visited, 0 ,sizeof(visited));
        if(canUse(i)) ans++;
    }

    cout << ans << endl;
    return 0;

}