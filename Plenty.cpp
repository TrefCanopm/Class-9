#include <iostream>
#include "Plenty.h"
#include "Error.h"

using namespace std;

Plenty::Plenty(int p)
{
	size = p;
	beg = new int[size];
	for (int i = 0; i < size; i++)
	{
		beg[i] = 0;
	}
}

int Plenty::operator[](int i)
{
	IndexError1 I1;
	IndexError2 I2;
	if (i < 0) throw I1;
	if (i >= size) throw I2;
	return beg[i];
}

Plenty Plenty::operator--()
{
	EmptySizeError Es;
	if (size == 0) throw Es;
	if (size == 1)
	{
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	};
	Plenty temp(size);
	delete[] beg;
	size--;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = temp.beg[i];
	return *this;
}

Plenty Plenty::operator-(const Plenty& p)
{
	if (size > p.size)
	{
		for (int i = 0; i < p.size; i++)
			beg[i] = beg[i] - p.beg[i];
	}
	else
	{
		for (int i = 0; i < size; i++)
			beg[i] = beg[i] - p.beg[i];
	}
	return *this;
}

int Plenty::operator()()
{
	return size;
}

ostream& operator<<(ostream& out, const Plenty& p)
{
	if (p.size == 0) out << "Empty\n";
	else
	{
		for (int i = 0; i < p.size; i++)
			out << p.beg[i] << " ";
		out << endl;
	}
	return out;
}
istream& operator >> (istream& in, Plenty& p)
{
	for (int i = 0; i < p.size; i++)
	{
		in >> p.beg[i];
	}
	return in;
}