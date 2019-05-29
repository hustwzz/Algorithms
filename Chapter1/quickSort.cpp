#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int b[], int lo, int hi);

void swap(int& a,int& b)
{
	int c = a;
	a = b;
	b = c;
}

void quickSort(int b[] ,int lo, int hi)
{
	if(hi - lo < 2) 
		return;
	int mi = partition(b, lo, hi - 1);
	quickSort(b, lo, mi);
	quickSort(b, mi + 1, hi);
}

int partition(int b[], int lo,int hi)
{
	swap(b[lo], b[lo + rand()%(hi - lo + 1)]);
	int pivot = b[lo];
	while(lo < hi)
	{
        while((lo < hi) && (pivot <= b[hi]))
				hi--;
			b[lo] = b[hi];
		while((lo < hi) && (pivot >= b[lo]))
			    lo++;
			b[hi] = b[lo];
	}
	b[lo] = pivot;
	return lo;
}

int main()
{
	int b[] = {2,3,44,3,222,-9,45,-89};
	quickSort(b, 0, 8);
	for(int i = 0;i < 8;++i)
		cout << b[i] << endl;
}