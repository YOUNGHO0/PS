#include <bits/stdc++.h>

using namespace std;

int memoi[100002] = { 0 };

int main()
{
	int num;
	int val;

	cin >> num >> val;
	int temp;
	int c;
	for (int i = 0; i < num; i++)
	{
		cin >> temp >> c;

		for (int i = val; i >= temp; i--)
		{
			memoi[i] = max(memoi[i], memoi[i - temp] + c);
		}
	}

	cout << memoi[val];

	return 0;
}