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

int n, m;
int visited[30] = { 0 };

vector<string>arr;

int dfs(pair<int, int> pos)
{
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int max_num = 1;
	for (int i = 0; i < 4; i++)
	{
		int ret = 1;
		pair<int, int> newpos = { pos.first + dx[i],pos.second + dy[i] };

		if (newpos.second < 0 || newpos.first < 0 || newpos.first >= m || newpos.second >= n)continue;

		if(visited[arr[newpos.second][newpos.first] - 'A'] == 0)
		{
			
			
				visited[arr[newpos.second][newpos.first] - 'A']++;
				ret += dfs(newpos);
				visited[arr[newpos.second][newpos.first] - 'A']--;
		
		
		}

		max_num = max(max_num, ret);
		
	}

	

	return max_num;

}

int main()
{
	cin >> n>> m;

	string s;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		arr.push_back(s);

	}
	visited[arr[0][0] - 'A'] = 1;
	int max = dfs({ 0,0 });

	


	cout << max;

}