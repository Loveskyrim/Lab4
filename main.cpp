#include <stdlib.h>
#include "element.h"
#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <ctime>
#include <string>
//#include <ostream>

using namespace std;
myelement& operator* (myelement& el1, myelement& el2)
{
	myelement*p;
		if (el1.modul!=el2.modul) //Операция недопустима при этом условии
		{
			p=new myelement(0,0); //Создаем несуществующий объект
		}
		else
		{
			int val=(el1.value*el2.value) % el1.modul;
			p=new myelement(el1.modul, val);
		}
		return *p;
}

ostream& operator<< (ostream& out, Matrix& mat1)
{
	return out;
}

ostream& operator<< (ostream& out, element& el2)
{
	out<< "Modul:"<<el2.Getmodul<<endl;
	out<< "Value:"<<el2.Getvalue<<endl;
	return out;
}

istream& operator>> (istream& in, element& el2)
{
	in>>"Modul:">>el2.Getmodul >> endl;
	in>>"Value:">>el2.Getvalue >> endl;
	return in;
}


ostream& operator<< (ostream& out, Matrix& mat1)
{
	out << mat1.n << " " << mat1.m << endl;
for (int i=0; i<mat1.n; i++)
	{
		
		for (int j=0; j<mat1.m; j++)
			out << mat1.pm[i][j] << " ";
		out << endl;
}
return out;
}

istream& operator>> (istream& in, Matrix& mat1)
{
	in >> mat1.n >> " " >> mat1.m;
for (int i=0; i<mat1.n; i++)
	{
		
		for (int j=0; j<mat1.m; j++)
			in >> mat1.pm[i][j] >> " ";
}
return in;
}
/*ostream& operator<<(ostream& out, myelement& el2)

{
	out<< "("<< el2.modul<< ", "<< el2.value<< ") ";
	return out;

}*/

void main()

{
	setlocale(LC_ALL, "Russian");
	
	myelement object1(17, 11), object2(17, 22), object3(17, 33), object4(17, 44);
	object3.Print();
	object4.Print();
	srand(time(0));
	
	int n, m;
	n=6; m=3;
	myelement **pm1, **pm2;
	pm1=new myelement*[n];
	pm2=new myelement*[n];
	int mod=rand() % 49+2;
	for(int i=0; i<n; i++)
	{
		pm1[i]=new myelement[m];
		pm2[i]=new myelement[m];
		for(int j=0; j<m; j++)
		{
			pm1[i][j].setEl(mod, rand() % 100);
			pm2[i][j].setEl(mod, rand() % 100);
		}
	}

	Matrix mat1(pm1, n, m), mat2(pm2, n, m),mat3,mat4, mat5;
	mat3=mat1+mat2;

	cout<<endl<<"Матрица 1:"<< endl;
	mat1.Print();
	cout<<endl<<"Матрица 2:"<< endl;
	mat2.Print();
	cout<< endl<<"Матрица1+Матрица2:"<< endl;
	mat3.Print();
	cout<<endl<<"Матрица перевернута"<<endl;
	mat5=!mat1;
	mat5.Print();
	cout<< endl<<"Конкатенация"<< endl;
	mat4=mat1|mat2;
	mat4.Print();
	/*cout<< "Элемент второй матрицы"<<endl;
	mat2.index(1,1).Print();*/
	cout<<endl;
	system ("pause");
}