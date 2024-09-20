#include <bits/stdc++.h>

using namespace std;
int main()
{
	int num;
	cin >> num;
	int temp;
	vector<int> len;
	vector<pair<int, int>> pa;
	int s = 0;
	for (int i = 0; i < num; i++)
	{
		
		cin >> temp;
			auto pos = lower_bound(len.begin(), len.end(), temp);
			
			int position = (int)(pos - len.begin());

			if (pos == len.end())
			{
				len.push_back(temp);
				s = s + 1;
			}
			else {
				len[position] = temp;
			}
	}
		
	cout << s << endl;
	
	



	return 0;
}