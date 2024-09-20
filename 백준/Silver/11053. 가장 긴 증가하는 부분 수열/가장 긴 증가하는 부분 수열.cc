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

			auto pos1 = len.end();
			auto pos = lower_bound(len.begin(), len.end(), temp);
			
			int position = (int)(pos - len.begin());

			if (pos == len.end())
			{
				len.push_back(temp);
				s = s + 1;
				pa.push_back({ temp,s});
			}
			else {
				len[position] = temp;
				pa.push_back({ temp,position+1 });
			}
	}
		
	
	//for (auto i : pa)
		//cout << "값: " << i.first << " 순위" << i.second << endl;
		
	cout << s << endl;
	
	



	return 0;
}