#pragma once
#include <iostream>

using namespace std;
class myelement
{
private:
	int modul, value;

public:
	
	myelement(void);
	myelement(int modul, int value);	
	void setEl(myelement & el);
	void setEl(int mod, int v);
	
	int Getmodul();
	int Getvalue();
	void Print();
	void PrintForMatr();
	
	myelement& operator+(myelement& el2);
	friend myelement& operator* (myelement& el1, myelement& el2);
	friend ostream& operator<<(ostream& out, myelement& el2);
	friend istream& operator>>(istream& in, myelement& el2);
	~myelement(void);
};

