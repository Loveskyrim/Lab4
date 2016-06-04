#pragma once
#include <string>
#include <iostream>
using namespace std;

class podrazdel;


class sotrudnik
{
	string fio;
	char stcom; // 0.не был, 1.отправлен, 2.вернулся, 3.была оплачена
	bool prem; //0....
	double oklad;
	podrazdel *pPodr;


public:

	//sotrudnik(const sotrudnik& sotr);
	sotrudnik(string fio1);
	sotrudnik();
	sotrudnik(string name1, double oklad1);
	void Print();
	double GetOklad();
	bool GetPrem();
	void SetPrem(bool flag);
	char GetState();
	string& GetFio();
	void PrintInFile(ostream& f);
	void readFromFile(istream& f);

	sotrudnik(string name1, double oklad1, podrazdel *p);
	friend class podrazdel;


	void AddtoPodr(podrazdel *p, double oklad1, ostream& out);
	void SetOklad(double newOkl, ostream& out);
	void SetPodr(podrazdel *p, ostream& out);
	bool operator==(const sotrudnik& s2);
	~sotrudnik(void);
};

