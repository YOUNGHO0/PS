#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int **arr;
int num_x;
int num_y;
queue<pair<int, int>> q;
int dydx[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void bfs()
{
	int count = 0;

	while (!q.empty())
	{


	pair<int, int> temp = q.front();
	q.pop();
	int new_x;
	int new_y;
	for (int i = 0; i < 4; i++)
	{
		new_y = temp.first + dydx[i][0];
		new_x = temp.second + dydx[i][1];

		if (0 <= new_y && new_y < num_y && 0 <= new_x && new_x < num_x)
		{
			if (arr[new_y][new_x] == 0)
			{
				arr[new_y][new_x] = arr[temp.first][temp.second]+1;
				q.push(make_pair(new_y, new_x));
			}
			
		}

	}

	}

	int max = -99;
	for (int i = 0; i < num_y; i++)
	{
		for (int j = 0; j < num_x; j++)
		{
			if (arr[i][j] == 0)
			{
				printf("-1");
				return;

			}
			else if (max < arr[i][j])
				max = arr[i][j];
		}
	}

	printf("%d", max - 1);
	


}


int main()
{
	
	cin >> num_x;
	cin >> num_y;
	

	arr = new int*[num_y];
	for (int i = 0; i < num_y; i++)
		arr[i] = new int[num_x];


	for (int i = 0; i < num_y; i++)
	{
		for (int j = 0; j < num_x; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}


	for (int i = 0; i < num_y; i++)
	{
		for (int j = 0; j < num_x; j++)
		{
			if (arr[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	bfs();
	

	return 0;
}