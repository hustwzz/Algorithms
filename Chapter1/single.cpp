#include <iostream>

using namespace std;

class singleton
{
	private:
	   singleton()
	   {
		   cout << "Constructor..." << endl; 
	   }
	public:
	   static singleton* single;
	   static singleton* getInstance() { return single; }
};

singleton* singleton::single = new singleton();

int main()
{
	singleton* d = singleton::getInstance();
	singleton* dd = singleton::getInstance();
	cout << d << '\t' << dd;
}