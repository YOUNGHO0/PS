#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int parent[200001];
int nfriend[200001];
map<string, int> m;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
	if (a > b)
	{
		parent[a] = b;
		nfriend[b] += nfriend[a];
	}
	else if (a < b)
	{
		parent[b] = a;
		nfriend[a] += nfriend[b];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, count;
	map<string, int> ::iterator it;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		m.clear();
		count = 0;
		for (int i = 0; i < 200001; i++) {
			parent[i] = i;
			nfriend[i] = 1;
		}

		string str1, str2;
		int F, a, b;
		cin >> F;

		for (int j = 0; j < F; j++)
		{
			cin >> str1 >> str2;
			it = m.find(str1);
			if (it == m.end()) {
				m[str1] = ++count;
				a = count;
			}
			else 
				a = it->second;

			it = m.find(str2);
			if (it == m.end()) {
				m[str2] = ++count;
				b = count;
			}
			else b = it->second;
			unionParent(a, b);
			int root = getParent(a);
			cout << nfriend[root] << '\n';
		}
	}
	return 0;
}