#pragma once
#include <iostream>

using namespace std;

class Plenty
{
	int size;
	int* beg;
public:
	Plenty() { size = 0; beg = 0; };
	Plenty(int);

	int operator [](int i);
	int operator () ();

	Plenty operator-(const Plenty&);
	Plenty operator--();

	friend ostream& operator<<(ostream& out, const Plenty&);
	friend istream& operator>>(istream& in, Plenty&);

	~Plenty() { delete[] beg; };
};