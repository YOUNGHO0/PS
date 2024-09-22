#include <iostream>    
#include <algorithm>    
#include <vector>       
#include <string.h>
#include <stack>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <map>
#include <set>
#include <sstream>
#include<stdio.h>


using namespace std;

int main()
{
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int>mm;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		mm.push_back(num);
	}

	int maxn = -1004;
	int sum = 0;
	for (int i = 0; i < mm.size(); i++)
	{
		sum += mm[i];
		maxn = max(maxn, sum);
		if (sum < 0)
			sum = 0;
	}

	cout << maxn;
	
	
	
}
