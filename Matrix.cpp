#include "Matrix.h"
#include "element.h"
#include <memory.h>
#include <iostream>
#include <ostream>


using namespace std;

Matrix::Matrix(void)
{
}

Matrix::Matrix(myelement **p, int n1, int m1)
{
	n=n1;
	m=m1;
	pm=new myelement*[n];
	for (int i=0; i<n; i++)
	{
		pm[i]=new myelement[m];
		for(int j=0; j<m; j++) pm[i][j].setEl(p[i][j]);
	//	memcpy(pm[i], p[i], sizeof(int)*m);
	}

}

	/*myelement& index(int n, int m)//Обращение по элементу
{
	
	
	return pm[n][m];
}*/


void Matrix::Print()

{
	for (int i=0; i<n; i++)
	{
		cout << endl;
		for (int j=0; j<m; j++)
		
			cout << pm[i][j] << " ";
				pm[i][j].PrintForMatr();
	
	}
}

Matrix& Matrix::operator+ (Matrix &mat1)// Сложение матриц
	{
		myelement ** pM=new myelement*[n];
		
		for (int i=0; i<n; i++)
		{
			pM[i]=new myelement[m];
			for (int j=0; j<m; j++)
				pM[i][j]=pm[i][j]+mat1.pm[i][j];
		}
		Matrix *p=new Matrix(pM, n, m);
		for (int i=0; i<n; i++) delete [] pM[i];
		delete [] pM;
		return *p;
	}


Matrix& Matrix::operator| (Matrix &mat1)// Конкатенация матриц
	{
		myelement ** pM=new myelement*[n];
		
		for (int i=0; i<n; i++)
		{
			pM[i]=new myelement[m+mat1.m];
			for (int j=0; j<m; j++)
				pM[i][j]=pm[i][j];
			for (int j=m; j<m+mat1.m; j++)
				pM[i][j]=mat1.pm[i][j-m];
		}
		Matrix *p=new Matrix(pM, n, m+mat1.m);
		for (int i=0; i<n; i++) delete [] pM[i];
		delete [] pM;
		return *p;
		
	}

Matrix& Matrix::operator! ()// Поворот матриц
	{
		myelement ** pM=new myelement*[m];
		
		for (int i=0; i<m; i++)
		{
			pM[i]=new myelement[n];
			for (int j=0; j<n; j++)
				pM[i][j]=pm[n-1-j][i];
		}
		Matrix *p=new Matrix(pM, m, n);
		for (int i=0; i<m; i++) delete [] pM[i];
		delete [] pM;
		return *p;
	}

	

Matrix::~Matrix(void)
{
}
