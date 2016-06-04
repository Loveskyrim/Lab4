#include "sotrudnik.h"
#include "podrazdel.h"


sotrudnik::sotrudnik(void)
{
	stcom=rand() % 4;// Командировка
}

sotrudnik::sotrudnik(string fio1)
{
	fio=fio1;
//	oklad=oklad1;
	//pPodr=p;
	stcom=rand() % 4;// Командировка
}

	void sotrudnik::Print()
	{
		cout<<  "FIO: " << fio << " oklad="<< oklad<<endl;/////
	}

	void sotrudnik::PrintInFile(ostream& f) 
	{
		f<< fio << endl<<oklad<<endl;/////
	}
	
	void sotrudnik::readFromFile(istream& f)
	{
		f>>fio>>oklad;
	}
	double sotrudnik::GetOklad()
	{
		return oklad;
	}
	
	bool sotrudnik::GetPrem()
	{
		return prem;
	}
	
	char sotrudnik::GetState()
	{
		return stcom;
	}

	sotrudnik::sotrudnik(string name1, double oklad1, podrazdel *p) // Конструктор включает сотрудника в подразделение
		{
			fio=name1;
			oklad=oklad1;
			pPodr=p;
			pPodr->listst.push_back(*this);
			stcom=rand() % 4;// Командировка
			if (rand() % 2) prem=true;
			else prem=false;
		}
	bool sotrudnik::operator==(const sotrudnik& s2)
	{
		return fio==s2.fio;
	}
	string& sotrudnik::GetFio()
	{
		return fio;
	}

	sotrudnik::sotrudnik(string name1, double oklad1) // Конструктор создает сотрудника без подразделения
		{
			fio=name1;
			oklad=oklad1;
			stcom=rand() % 4;// Командировка
			if (rand() % 2) prem=true;
			else prem=false;
		}
	void sotrudnik::SetPrem(bool flag)
	{
		prem=flag;
	}



	void sotrudnik::SetOklad(double newOkl, ostream& out)
	{
		oklad=newOkl;
		out << endl << "Изменение оклада сотрудника " << fio << " Новый оклад: " << oklad ;

	}

	void sotrudnik::SetPodr(podrazdel *p, ostream& out)
	{
		pPodr=p;
		pPodr->listst.push_back(*this);
		out << endl << "Сообщение об изменении" ;///////
	}

		void sotrudnik::AddtoPodr(podrazdel *p, double oklad1, ostream& out)
		{
			oklad=oklad1;
			pPodr=p;
			pPodr->listst.push_back(*this);
			out << endl << "Сообщение об изменении" ;///////
		}


sotrudnik::~sotrudnik(void)
{
}
