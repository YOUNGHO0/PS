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

bool compare(pair<int, int>a, pair<int, int>b)
{
	if (b.second == a.second)
	{
		return a.first > b.first;
	}
	else
	{
		return a.second > b.second;
	}
}

vector<int> num;
string s;
string s2;
int arr[4000004] = { 0 };
vector<int> arr2;
int main()
{
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; i*j <= n; j++)
			arr[i * j] = 1;
	}
	//arr2.push_back(0);
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
			arr2.push_back(i);

	}

	int l, h;

	l = 0;
	h = 0;
	int count = 0;
	int sum = 0;

	
	while (1)
	{
		if (l == arr2.size() || h == arr2.size())
			break;
		sum = 0;
		for (int i = l; i <= h; i++)
		{
			sum += arr2[i];
		}

		
		if (sum == n)
		{
			
			h++;
			count++;
		}
		else if (sum > n)
		{
			l++;
		}
		else if (sum < n)
		{
			h++;
		}
		

	}
	
	cout << count;
	
}
