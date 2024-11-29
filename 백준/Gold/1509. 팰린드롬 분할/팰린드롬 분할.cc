#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int arr[2504][2504] = { 0 };
int arr2[2504] = { 0 };
const int INF = 987654321;
string str;
int go(int here)
{
	if (here == str.size())
		return 0;
	if (arr2[here] != INF)
		return arr2[here];

	int& ret = arr2[here];

	for (int i = 0; here + i < str.size(); i++)
	{
		if (arr[here][here + i] == 1)
		{
			ret = min(ret, 1+ go(here + i+1));
		}
		
	}

	return ret;
	


}

int main()
{
	
	cin >> str;

	fill(arr2, arr2 + 2504, INF);

	for (int i = 0; i < str.size(); i++)
	{
		arr[i][i] = 1;
		
	}

	for (int i = 0; i < str.size(); i++)
		if (str[i] == str[i + 1])
			arr[i][i + 1] = 1;

	for (int i = 2; i < str.size(); i++)
	{
		for (int j = 0; i+j < str.size(); j++)
		{
			if (str[j] == str[j + i] && arr[j + 1][j + i - 1] == 1)
			{
				arr[j][j + i] = 1;
			}
		}
	}

	cout<<go(0);


	return 0;
}