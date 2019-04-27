#include <iostream>
#include <queue>
#define N 7

using namespace std;

int graph[N][N] = { {0 ,1 ,1 ,0 ,0 ,0 ,0},
{0 ,0 ,1 ,1 ,1 ,0 ,0},
{0 ,0 ,0 ,0 ,1 ,0 ,0},
{0 ,0 ,0 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,1 ,0 ,1 ,1},
{0 ,0 ,0 ,0 ,0 ,0 ,0},
{0 ,0 ,0 ,0 ,0 ,1 ,0}
};

int visited[N] = {0};

void BFS(int i)
{	
	visited[i-1] = 1;
	queue<int> q;
	q.push(i);
	while(!q.empty())
	{
		int j = q.front();
		cout << j << " ";
		q.pop();
		for(int m = 0;m < N;++m)
		{
			if(!visited[m]&&graph[j-1][m]==1)
			{
			q.push(m+1);
			visited[m] = 1;
			}
		}
	}
}

int main()
{
	for(int i = 1;i <= N;++i)
	{
		if(visited[i-1])
		   continue;
		BFS(i);
	}
	return 0;
}