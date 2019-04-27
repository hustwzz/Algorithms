#include <iostream>
#include <vector>

#define N 8

using namespace std;

int graph[N][N] = {{0, 4, 0, 6, 0, 0, 7, 0},
	               {4, 0, 12, 0, 0, 0, 0, 0},
	               {0, 12, 0, 9, 1, 2, 0, 10},
                   {6, 0, 9, 0, 13, 0, 2, 0},
	               {0, 0, 1, 13, 0, 5, 11, 8},
	               {0, 0, 2, 0, 5, 0, 0, 7},
                   {7, 0, 0, 2, 11, 0, 0, 14},
	               {0, 0, 10, 0, 8, 7, 14, 0}
};

int visited[N] = {0};

void prim(vector<int>& vec, int& sum, int& i)
{
	int min = 2111111;
	
	
	if(vec.size() == 0)
	{
		vec.push_back(i);
		visited[i-1] = 1;
	}
	else
	{
		for(auto s:vec)
		{
			for(int j = 0; j < N; ++j)
			{
				if(!visited[j] && graph[s-1][j] != 0)
				{
					if(min > graph[s-1][j])
					{
						min = graph[s-1][j];
						i = j+1;
					}
				}
			}
		}
		cout << min << '\t';
		sum += min;
		vec.push_back(i);
		visited[i-1] = 1;
	}
}

int main()
{
	vector<int> vec;
	int sum = 0;
	int i = 1;
	while(vec.size() != N)
      prim(vec, sum, i);
    cout << sum << endl;
	for(auto s : vec)
		cout << s << '\t';
	
	return 0;
};