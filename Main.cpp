#include <iostream>
#include "Error.h"
#include "Plenty.h"

using namespace std;

int main()
{
	try
	{
		Plenty x(2);
		Plenty y;
		cout << x;
		cout << "Nomer?";
		int i;
		cin >> i;
		cout << x[i] << endl;
		cout << y;
		--x;
		cout << x;
		--x;
		cout << x;
		--x;
	}
	catch(Error e)
	{
		e.what();
	}
	return 0;
}