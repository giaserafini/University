#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <random>


int randomInt(int min, int max) {
	static std::default_random_engine e{};
	std::uniform_int_distribution<int > d(min, max);
	return d(e);
}


void exe1()
{
	
	std::vector<int> v1;
	int n;
	std::cout << "enter v1 ";
	std::cin >> n;
	for (int i = 0;i < n;i++)
	{ 
		int a=randomInt(-20, 20);
		v1.push_back(a);
		std::cout << a<<endl;
	}	
	auto b=v1.begin(), e= v1.end();
	int u;
	std::cout << "what do you want to delete ";
	std::cin >> u;
	for (auto it=b;it!=e;it++)
	{
		if (*it == u)
			v1.erase(it);
		else 
			std::cout << *it<<endl;
		
	}



	
	std::cout << "what do you want to find ";
	std::cin >> u;
		if(std::find(b,e,u)==b)
			std::cout << "there's "<<endl;
		else
			std::cout << "there's no "<<endl;


		std::sort(b, e);
		std::cout << "sorted" << endl;
		for (auto it = b;it != e;it++)
		{ 
			std::cout << *it;
			std::cout<<"   "<<std::count(b, e, *it)<<endl;
		}

		
		

}

void exe2()
{
	list<int> l1;
	int n;
	std::cout << "enter l1 ";
	std::cin >> n;
	for (int i = 0;i < n;i++)
	{
		int a = randomInt(-20, 20);
		l1.push_back(a);
		std::cout << a << endl;

	}
	int u;
	std::cout << "what do you want to delete ";
	std::cin >> u;
	for (auto it = l1.begin();it != l1.end();it++)
	{
		if (*it == u)
			l1.erase(it);
		else 
			std::cout << *it<<endl;

	}


	auto b = l1.begin(), e = l1.end();
	std::cout << "what do you want to find ";
	std::cin >> u;
	if (std::find(b, e, u) == b)
		std::cout << "there is " << endl;
	else
		std::cout << "there's no " << endl;
	

}


void exe3() {
	exe1();
	exe2();
}



int main()
{
	exe1();
	exe2();
	exe3();
	return 0;
}