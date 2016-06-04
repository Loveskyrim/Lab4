#include "podrazdel.h"
#include "sotrudnik.h"

podrazdel::podrazdel(void)
{
}

podrazdel::podrazdel(string name1)
{
		name=name1;
}

	
void podrazdel::AddSotr(sotrudnik& sotr, ostream& out)
{
		listst.push_back(sotr);
}

podrazdel::~podrazdel(void)
{
}

list <sotrudnik>& podrazdel::getList()
{
	return listst;
}

void podrazdel::setprimiy(double sum)
{
	int N=0; 
	for(auto pos: listst)
		if (pos.GetPrem()==true) N++;
	cout<<"Premiy pologena "<<N<<" sotrudnikam"<<endl;
	for(auto pos: listst)
		if (pos.GetPrem()==true) {
			pos.Print();
			cout<<" Premiy: "<<sum/N<<endl;
		}


}

void podrazdel::print()
{
	cout<<"Podr name: "<<name<<endl;
	for(auto pos: listst)
		pos.Print();
}

podrazdel& podrazdel::operator+(sotrudnik& st)
{  // Сотрудник не включен в другое подразделение
	listst.push_back(st);
	st.pPodr=this;
	return *this;
}

podrazdel& podrazdel::operator-(sotrudnik& st)
{  // Поиск сотрудника
	list<sotrudnik>::iterator pos;
	for(pos=listst.begin(); pos!=listst.end(); ++pos)
		if ((*pos).GetFio()==st.GetFio()) {
			pos->pPodr=0;
		//	listst.remove(*pos);
			listst.erase(pos); 
			break;
		}
	return *this;
}

void podrazdel::PrintInFile(ostream& fout)
{
	fout<<name<<endl<<listst.size()<<endl;
	for(auto pos: listst)
		pos.PrintInFile(fout);

}
void podrazdel::readFromFile(istream& fin, ostream& out)
{
	int n;
	fin>>name>>n;
	sotrudnik *pSotr;
	for(int i=0; i<n; i++)
	{
		pSotr=new sotrudnik;
		pSotr->readFromFile(fin);
		pSotr->SetPodr(this, out);

	}

}

string & podrazdel::getName()
{
	return name;
}

double podrazdel::getZarp() // Получение суммы зарплаты для подразделения
{
	double sum=0;
	for(auto pos: listst)
		sum+=pos.GetOklad();
	return sum;
}