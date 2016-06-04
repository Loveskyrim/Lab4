#pragma once


#include <string>
#include  <list>
#include <iostream>
using namespace std;


class sotrudnik;

class podrazdel
{
	string name;
	list <sotrudnik> listst;
public:
	list <sotrudnik>& getList();
	
	podrazdel(string name1);
	podrazdel(string name1, double oklad1, podrazdel *p);
	void print();
	void AddSotr(sotrudnik& sotr, ostream& out);
	void PrintInFile(ostream& fout);
	void readFromFile(istream& fin,  ostream& out);
	double getZarp(); // Получение суммы зарплаты для подразделения
	string & getName();
	void setprimiy(double sum);
	podrazdel& operator+(sotrudnik& st);
	podrazdel& operator-(sotrudnik& st);
	
	podrazdel(void);
	~podrazdel(void);
	friend class sotrudnik;
};

