#include "stdafx.h"
#include<iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include<fstream>
#include<map>
using namespace std;



//zad1
void zadanie1()
{
	int i=0;
	
	string a;	vector<string> v1;
	map<string, int> m;	ifstream dane("macbeth.txt");
	while (dane.eof() != true)
	{

		dane >> a;
		string a2;
		for(auto &e:a)
		{ 
			if (e == '.' || e == ',' || e == '\'' || e == '?' || e == '?' || e == '!' || e == ':' || e == ',' || e == '[' || e == ']' || e == ';' || e == '-')
			{
				e = ' '; continue;
			}
			if (int(e)>=65 && int(e) <= 90)
			{ 
				int b = int(e);
				b+= 32;
				e = char(b);
			}
			a2 += e;
			
		}
		m[a2]++;
		v1.push_back(a2);
		i++;
	}
	
	cout <<  endl;
	vector<int> v2(20,0);
	vector<string> v3(20, "0");
		
	for(auto it=m.begin();it!=m.end();it++)	
	{ 
	//cout <<it->first<<"  "<<it->second<<endl;
		for (int i = 0;i < 20;i++)
	{
		if(it->second>v2[i])
		{
			v2[i] = it->second;
			v3[i] = it->first;
			i = 20;
		}
	}
	}

	for (int i = 0;i < 20;i++)
	{
		cout << v3[i] << "  " <<v2[i] << endl;

	}

}

void zadanie2() {
	zadanie1();
}

void zadanie3() {

	zadanie1();

}




int main()
{
	int a, b = 0, z = 0;
	do
	{
		z = 0;
		cout << " ktore zadanie?  ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "zad 1  " << endl;
			zadanie1();

			cout << endl;
			break;
		}
		case 2:
		{
			cout << "zad 2 " << endl;
			zadanie2();

			cout << endl;
			break;
		}
		case 3:
		{

			cout << "zad  3 " << endl;
			zadanie3();

			cout << endl;
			break;
		}
		/*case 4:
		{

			cout << "zad 4 " << endl;
			zadanie4();


			cout << endl;
			break;
		}
		case 5:
		{

			cout << "zad 5 " << endl;

			zadanie5();
			cout << endl;
			break;
		}
		case 6:
		{

			cout << "zad 6 " << endl;
			zadanie6();


			cout << endl;
			break;
		}
		case 7:
		{

			cout << "zad 7 " << endl;
			zadanie7();


			cout << endl;
			break;
		}/*
		 case 8:
		 {

		 cout << "zad 8 "<<endl;
		 zadanie8();


		 cout << endl;
		 break;
		 }
		 case 9:
		 {

		 cout << "zad 9 "<<endl;
		 zadanie9();
		 cout << endl;
		 break;
		 }
		 /*case 10:
		 {
		 cout << "zad 10 "<<endl;
		 zadanie10();
		 cout << endl;
		 break;
		 }*/


		default:
			cout << " zly numer " << endl;
			break;
		}






		cout << endl;
		cout << " kontynuowac? " << endl;
		cout << " 1-tak   2-nie ";
		while (z != 1 && z != 2)
		{
			cin >> z;
			if (z == 2)
				b = 1;
			else
				if (z == 1)
					b = 0;
				else
					cout << " zly numer " << endl;
		}
		cout << endl;
	} while (b != 1);
	return 0;
}