#include "element.h"
#include <iostream>
#include <ostream>
using namespace std;

myelement::myelement(void)
{
}

myelement::myelement(int modul, int value)
{
	this->modul=modul;
	if (modul>0) this->value= value % modul;
}	

	
int myelement::Getmodul()
{
	return modul;
}
int myelement::Getvalue()
{
return value;
}

void myelement::PrintForMatr()
{
	cout<< "("<< modul<< ", "<< value<< ") ";
}


	void myelement::Print()
	{
		if (modul!=0)
		cout << endl << "modul=" << modul << " value =" << value;
		else cout << endl << "object does not exist";
	}

	myelement& myelement::operator+(myelement& el2)
	{
		myelement*p;
		if (modul!=el2.modul) //Операция недопустима при этом условии
		{
			p=new myelement(0,0); //Создаем несуществующий объект
		}
		else
		{
			int val=(value+el2.value) % modul;
			p=new myelement(modul, val);
		}
		return *p;
	}

	void myelement::setEl(myelement & el)
	{
		this->modul=el.modul;
	    this->value= el.value;
	}
	void myelement::setEl(int mod, int v)
	{
		modul=mod;
		value=v;
	}



myelement::~myelement(void)
{
}
