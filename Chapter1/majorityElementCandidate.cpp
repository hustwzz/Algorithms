#include <iostream>
#include <vector>
using namespace std;

int majorityElementCandidate(vector<int>& vec)
{
	int maj = 0;
	for(int c = 0, i = 0;i < vec.size();++i)
	{
		if(c == 0)
			maj = vec[i];
		else
			maj == vec[i] ? c++:c--;
	}
	return maj;
}

int main()
{
	vector<int> vec = {1,1,2,2,4,4,4,4,4};
	cout << majorityElementCandidate(vec);
	return 0;
}