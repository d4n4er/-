#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
#include <stdio.h>
#include <iomanip>

using namespace std;
int menu =1 ;
struct Univer
{
       int code;
       char name [20];
       char address [20];
       long number;
       string fsp;
	   int students;
	   char pulpit[15];
};

	 Univer* OurUnivers = 0;
     int univerAmount =0;
     int YesOrNot = 0; 
    

Univer* AddStruct(Univer* Obj, const int amount);      //выделение памяти 
void setData(Univer* Obj, const int amount);          //ввод данных в структуру
void showData(const Univer* Obj, const int amount);  //вывод данных

int factorial(int n = 10)
{

	if (n<1)
	return 1;
		else
		return n * factorial (n-1);
}
 int factorial (float n, float i)
 	{
 		if (n+i<1)
		return 1;
			else
			return n * factorial (n-1);
 	} 
 	
 	int prog (int& menu) //link
 	{
 		while (menu != 3)
	{
			cout << "1-добавить элемент \n" << "2- вывести структуру \n"<<"3-выход \n";
			cin >> menu;
	
	switch (menu){
	
	case 1:
		{

    do
 {
 OurUnivers = AddStruct(OurUnivers, univerAmount);
 setData(OurUnivers, univerAmount);
 
 univerAmount++;
 
 cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
 cin >> YesOrNot;
 cin.get();
 } while (YesOrNot != 0);

 break;
	}
break;

 case 2:

	 
 
 showData(OurUnivers, univerAmount);
 
 //	delete[] OurUnivers;
		break;
	
	case 3:
{
				cout << "досвидания";
		int out(3);
}
		break;
		
		default:
			cout << "Код ошибки: " << factorial (10) << endl << "Ошибка 3628800, введи что-нибудь еще \n";
			
		break;
}
	 }
 }
int main()
{
			
	setlocale(LC_ALL, "rus");
	int menu =1 ;
	
	prog(menu);
		
	

	return 0;
}
	


int out (int* menu) //ukaz
 {
 
 }
 	


Univer* AddStruct(Univer* Obj, const int amount)
{
	if (amount == 0)
	{		
		Obj = new Univer[amount + 1];
	}
	else
	{
		Univer* tempObj = new Univer [amount + 1];

		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = Obj[i]; //копируем во временный объект
		}
		delete [] Obj;

		Obj = tempObj;		
	}		
	return Obj;
}
inline void setData(Univer* Obj, const int amount)
{
		cout << "Код: ";
		cin >> Obj[amount].code;
		cout << "Название: ";
		cin >> Obj[amount].name;
	//	getline (cin, Obj[amount].name);
	//	cin.getline(Obj[amount].name, 32);
		cout << "Адрес: ";
		cin >> Obj[amount].address;
	//	getline (cin, Obj[amount].address);
	    cout << "Номер: ";
		cin >> Obj[amount].number;
		cout << "ФИО директора: ";
		//cin >> Obj[amount].fsp;
		getchar();
		getline (cin, Obj[amount].fsp);
		cout << "Кол-во студентов: ";
		cin >> Obj[amount].students;
		cout << "Кафедра: ";
		cin >> Obj[amount].pulpit;
	//	getline (cin, Obj[amount].pulpit);  
		cin.get(); 
		cout << endl; 	
}


void showData(const Univer* Obj, const int amount)
{
 system("cls");
 cout << "№  " <<setw(11) << "Код\t" << setw(21) << "Название\t"<< setw(21)<< "Адрес\t"<< setw(16) << "Номер\t" <<setw(31) << "ФИО директора\t"<<setw(15) << "Кол-во студентов\t" <<setw(8) << "Кафедра\t" <<  endl;
 cout << "===============================================================================================================================================" << endl;
 for (int i = 0; i < amount; i++)
 {
 	
 /*	printf("%2d\t%2d\t%5s\t%5s\t%2d\t%5s\t%2d\t%5s\n",i+1,Obj[i].code,Obj[i].name.c_str(),Obj[i].address.c_str(),Obj[i].number,Obj[i].fsp.c_str(),Obj[i].students,Obj[i].pulpit.c_str()); */
    cout << i + 1 << "  " << setw(10) << Obj[i].code << '\t' << setw(20) << Obj[i].name << '\t'<< setw(20)<< Obj[i].address  << '\t'<< setw(15) << Obj[i].number << '\t'<< setw(30) << Obj[i].fsp << '\t' << setw(10)<< Obj[i].students << '\t' << setw(15) << Obj[i].pulpit << endl; 
 }
system ("pause");
} 
