#include <iostream>
#include "sotrudnik.h"
#include "podrazdel.h"
#include <locale.h>
#include <fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	podrazdel	*pPodr;
	sotrudnik   *pSotr;
	string name;
	double oklad;
	ofstream *ofs; // Объект - файл для записи
	ifstream *ifs; // Объект - файл для чтения
	list<podrazdel> listPodr;
	while (1)
	{

	
	cout << endl << "Выбор режима ";
	cout << endl << "1-ввод данных, 2-чтение из файла, 3-запись в файл, 4-печать данных, 5-печать суммарной зарплаты для подразделений, 6- вывод сотрудников с оплаченной командировкой, 7- печать всех данных, 8- выбор сотрудника, 9- Назначение премии подразделению 10-выход" << endl;
	int reg;
	cin >> reg;
	bool flag;
	int n;
	ofstream myLog("MyLog.txt");
	try
	{
	
	switch (reg)
	{
	case 1://ввод данных (1 подразделение)
		cout << "Введите название подразделения: "<< endl;
		cin >> name;
		pPodr=new podrazdel(name);
		do
		{
			cout<< "Введите ФИО сотрудника:"<< endl;
				cin >> name;
				cout <<"Введите оклад"<<endl;
				cin >> oklad;
				pSotr=new sotrudnik(name, oklad);
				*pPodr+*pSotr;// Включаем сотрудника в подразделение
				cout <<"Продолжить ввод сотрудников? 1-да, 0-нет"<< endl;
				cin >> flag;
		} while (flag);
		
		listPodr.push_back(*pPodr); // ДОбавляем подразделение в список
		
		
		break;
	
	case 2:// чтение из файла
		ifs=new ifstream("MyData.dat");
		listPodr.clear();
		*ifs>>n;
		for(int i=0; i<n; i++) {
			pPodr=new podrazdel;
			pPodr->readFromFile(*ifs, myLog);
			listPodr.push_back(*pPodr); // ДОбавляем подразделение в список
		}
		ifs->close();
		delete ifs;

	break;
		
	case 3:// запись в файл	
		ofs=new ofstream("MyData.dat");
		*ofs<<listPodr.size()<<endl;
		for(auto pos: listPodr) pos.PrintInFile(*ofs);
		ofs->close();
		delete ofs;

		break;
	case 4: // Печать данных
		for(auto pos: listPodr) 
			pos.print();

		break;
	case 5: // Расчет зарплаты для подразделений
		for(auto pos: listPodr) 
			cout<<pos.getName()<<' '<<"Сумма зарплаты: "<<pos.getZarp()<<endl;
		break;

	case 6:
		flag=0;
		for(auto pos: listPodr) 
		{
			cout<<pos.getName()<<endl;
			for(auto pos2: pos.getList()) if (pos2.GetState()==3) {
				pos2.Print();
				flag=1;
			}
		}
		if (flag==0)
			cout<<"List is empty"<<endl;
		break;
	case 7: // Печать всех данных
		for(auto pos: listPodr) 
		   pos.print();

		break;
	case 8:
		{
			
		cout<<"Введите название подразделения: "; cin>>name;
		list<podrazdel>::iterator pos, pos1;
	    for(pos=listPodr.begin(); pos!=listPodr.end(); ++pos)
		if ((*pos).getName()==name) {
			 break;
		}
		if (pos==listPodr.end())
		{
			throw "Нет подразделения с именем "+name;
		}
		string name2;
		cout<<"Введите ФИО сотрудника: "; cin>>name2;
		list<sotrudnik>::iterator pos2;
	    for(pos2=pos->getList().begin(); pos2!=pos->getList().end(); ++pos2)
		if ((*pos2).GetFio()==name2) {
			 break;
		}
		if (pos2==pos->getList().end())
		{
			throw "Нет сотрудника "+name2+" в подразделении "+name;
		}
		pos2->Print();
		cout<<" Действия с сотрудником: 1- Перевести 2- Уволить 3- изменить зарплату 4- назначить премию 5- отменить премию 6- выход к главному меню: ";
		int reg2;

		cin>>reg2;
		switch(reg2)
		{
		case 1: 
			{
			cout<<"Введите название подразделения для перевода: "; cin>>name;
			
	        for(pos1=listPodr.begin(); pos1!=listPodr.end(); ++pos1)
		      if ((*pos1).getName()==name) {
			 break;
			}
			if (pos1==listPodr.end())
			{
				throw "Нет подразделения с именем "+name;
			}
			// Перевод
			sotrudnik *pSotr=new sotrudnik(*pos2);
			(*pos)-(*pos2);
			(*pos1)+(*pSotr);
			}
			break;
		case 2:
			(*pos)-(*pos2);
			
			break;
		
		case 3:
			cout<<"Новая зарплата: "; cin>>oklad;
			pos2->SetOklad(oklad, myLog);
			break;
		case 4:
			
			pos2->SetPrem(true);
			cout<<"Премия назначена."<<endl;
			break;
		case 5:
			
			pos2->SetPrem(false);
			cout<<"Премия отменена."<<endl;
			break;
		case 6:
			break;
		
		} // switch(reg2)
		}
		break;

	case 9: // Назначение премии подразделению
		{
			cout<<"Введите название подразделения: "; cin>>name;
		   list<podrazdel>::iterator pos;
	        for(pos=listPodr.begin(); pos!=listPodr.end(); ++pos)
		    if ((*pos).getName()==name) {
			      break;
		    }
		    if (pos==listPodr.end())
			{
			throw "Нет подразделения с именем "+name;
		    }
			double summa;
			cout<<"Суммарный размер премии для всего подразделения: "; cin>>summa;
			pos->setprimiy(summa);
		}
		break;
			


	case 10:// выход
		myLog.close();
		return;
	}
	}  // Конец try
	catch(string str)
	{
		cout<<"Возникло исключение: "<<str<<endl;

	}
	}
}