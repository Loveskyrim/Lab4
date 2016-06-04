#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class myelement;

class Matrix
{
	myelement **pm;
	int n,m; //n-строки, m-столбцы

public:
//	myelement& index(int n1, int m1);
	Matrix(void);
	Matrix(myelement **p, int n1, int m1);
	void Print();
	Matrix& operator+ (Matrix &mat1);
	Matrix& operator| (Matrix &mat1);
	Matrix& operator! ();
	friend ostream& operator<< (ostream& out, Matrix& mat1);
	friend istream& operator>> (istream& in, Matrix& mat1);
	
	~Matrix(void);
};

