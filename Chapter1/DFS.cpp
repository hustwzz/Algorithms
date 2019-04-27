#include <iostream>
#include <stack>
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

void DFS(int i)
{	
	visited[i-1] = 1;
	stack<int> s;
	s.push(i);
	while(!s.empty())
	{
		int j = s.top();
		cout << j << " ";
		s.pop();
		for(int m = 0;m < N;++m)
		{
			if(!visited[m]&&graph[j-1][m]==1)
			{
			s.push(m+1);
			visited[m] = 1;
			break;
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
		DFS(i);
	}
	return 0;
}