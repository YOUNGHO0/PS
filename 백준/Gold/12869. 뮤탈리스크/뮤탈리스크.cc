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

int visited[64][64][64] = { 0 };
int num;

bool compare(pair<vector<int>, int> a, pair<vector<int>, int>b)
{
	return a.second < b.second;
}

void bfs(vector<int> scv)
{
	vector< pair<vector<int>, int>> res;
	queue<pair<vector<int>,int>> q;
	q.push({ scv,1 });

	vector<int> mutal;
	mutal.push_back(9);
	mutal.push_back(3);
	mutal.push_back(1);
	

	while (!q.empty())
	{
		 pair<vector<int>, int> temp = q.front();
		q.pop();
		int temp2[3] = { 0 };
		sort(mutal.begin(), mutal.end());
		do {
			int flag = 0;
			for (int i = 0; i < num; i++)
			{
				temp2[i] = temp.first[i];
				temp.first[i] -= mutal[i];
				
				if (temp.first[i] > 0)
					flag = 1;
				else if (temp.first[i] < 0)
					temp.first[i] = 0;
			}
			if (flag == 0)
			{
				res.push_back(temp);
			
			}	
			else if(visited[temp.first[0]][temp.first[1]][temp.first[2]] == 0)
			{
				
				visited[temp.first[0]][temp.first[1]][temp.first[2]] = 1;
				temp.second++;
				q.push(temp);
				temp.second--;
			}

			for (int i = 0; i < num; i++)
			{
				temp.first[i] = temp2[i];
			}

		} while (next_permutation(mutal.begin(), mutal.end()));

	

	
	}

	sort(res.begin(), res.end(), compare);

	
	cout << res[0].second;
	

}


int main()
{


	vector<int> scv;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int nu;
		cin >> nu;
		scv.push_back(nu);
	}

	if (num == 1)
	{
		scv.push_back(0);
		scv.push_back(0);
	}
	else if (num == 2)
		scv.push_back(0);
	bfs(scv);

	return 0;
}