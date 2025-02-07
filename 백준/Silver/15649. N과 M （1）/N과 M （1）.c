#include <stdio.h>
#include <stdlib.h>

int visited[10] = { 0 };
int answer[10] = { 0 };
int total_number;
int final_stage;

void solve(int stage_number)
{
	int i, j, k;

	if (stage_number == final_stage)
	{
		for (i = 0; i < final_stage; i++)
		{
			printf("%d ", answer[i]);
		}
		printf("\n");
		return;
	}
	else if (stage_number < final_stage)
	{
		for (i = 0; i < total_number; i++)
		{
			if (visited[i] == 0)
			{
				answer[stage_number] = i + 1;
				visited[i] = 1;
				solve(stage_number + 1);
				visited[i] = 0;

			}
		}
	}


	

	
}



int main()
{
	int n, m;
	int visited[10] = { 0 };
	int i, j, k;


	scanf("%d %d", &total_number, &final_stage);

	solve(0);

	return 0;



}