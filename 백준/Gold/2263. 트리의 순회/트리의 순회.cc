#include <bits/stdc++.h>

using namespace std;

int inorder[100002]={0};
int postorder[100002]={0};
int inorderPos[100002]={0};


void preOrder(int start, int end, int instart , int inend){

    if(start> end || instart > inend) return;

    int root = postorder[end];
    cout << root << " ";

    int mid = inorderPos[root];
    int leftSize = mid - instart;
    int rightSize = inend - mid;

    preOrder(start,start+leftSize-1,instart, mid-1 );
    preOrder(start+leftSize,end-1,mid+1, inend );


}






int main(){


       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int number = 0;

    cin >> number;

    int temp;

    for(int i =0; i<number; i++){
        cin >> inorder[i];
        inorderPos[inorder[i]]= i;
        
    }

    for(int i =0; i<number ; i++){
        cin >> postorder[i];
    }

    preOrder(0,number-1,0,number-1);







    return 0;
}