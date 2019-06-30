#include"stdafx.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>



class timespan {
public:
	unsigned int hours = 0;
	unsigned int minutes = 0;
	unsigned int seconds = 0;


	timespan(unsigned int seconds) {
		this->seconds = seconds;
		if (this->minutes > 59)
			while (this->minutes > 59)
			{
				this->hours++;
				this->minutes = this->minutes - 60;
			}
		if (this->seconds>59)
			while (this->seconds>59)
			{
				this->minutes++;
				this->seconds = this->seconds - 60;

			}
		
								}

	void com() {
		std::cout << "hours " << hours << endl;
		std::cout << "mins " << minutes << endl;
		std::cout << "secs " << seconds << endl;
	}


};

void exe1() {
	std::cout << "enter a number of secs " << endl;
	unsigned int s;
	std::cin >> s;
	timespan ts(s);
	ts.com();
	
}




class Students {
public:
	std::string name;
	std::string surname;
	std::string Id;

	Students(){name= surname= Id='0';}
	

	void add(list<Students> a)		
	{		 
		std::cout << "name, surname, id "<<endl;
		std::cin >> name >> surname >> Id;  
	}

	void delete(list<Students>& a, std::string Idd)
	{
		int z = 0;		
		for (auto e = a.begin(); e != a.end(); e++)	
			if (e->id == id2)
		{
			e = a.erase(e);	cout << "an item has been deleted" << endl;
			z = 1;
		}			
		if (z == 0) { cout << "wrong id" << endl; 
		}
	}
	

	void print(list<Students>a)
	{		
		for (auto e : a)		
		std::cout <<e.name<< "  "<<e.surname<<"  "<<e.Id<<endl;	
		std::cout << endl;		
	}


	


	void find(list<Students> a, std::string idd) 
	{
		int z = 0;	f
for (auto e = a.begin();e != a.end();e++)		
if (e->id == id2) {
			cout << e->name << "  " << e->surname << "  " << e->Id << endl;
			z = 1;
}
		if (z == 0)	cout << " an item couldn't be found" << endl;
	}


	void file(list<Students> a) 
	{		ofstream w("lista.txt");
			for (auto e = a.begin();e != a.end();e++)			
				w << e->name << "  " << e->surname << "  " << e->Id << endl;
			std::cout << "da list has been added kinto a file" << endl;
			ifstream l("lista.txt");
			std::cout << "reading: " << endl;
			if (l)	while (l.eof() != true) {		l >> name >> surname >> id;
			std::cout << name << "  " << surname << "  " << Id<<endl;	}
	}

};


void exe2()
{
	Students students;
	list<Students> a;
	std::string idd;
	int num = 1;
	
	while (num!=0)
	{

		std::cout << endl;
		std::cout << "0 end, 1 add,	 2 delete,	 3 write a list, 4 found an Id, 5 add to file,	6 delete list,	7 autofill 10  " << endl;
		std::cin >> sum;
			   
		if(num==1)
		{		students.add(a);	a.push_back(students);	}
		
		else if(num==2) 
		{	
			std::cout << endl << "which Id do you want to delete " << endl;		
			std::cin >> idd;
			students.delete(a, idd);			}
	

		else if (num == 3)
		{		std::cout << endl << "lista:    (name, sur, id)" << endl;		students.print(a);		}


		else if (num == 4)
		{		std::cout << "enter an ID" << endl;		 std::cin >> idd;		students.find(a, idd);		}


		else if (num == 5)
		{		students.file(a);		}


		else if (num == 6)
		{		a.clear();		std::cout << "cleared" << endl;		}


		else if (num == 7)
		{	
			students b;	
			std::cout<< "a list has been filled" <<endl;
			for (int i = 0;i < 10;i++)
			{ b.name = char(65+i);		 b.surname = char(i + 97);		 b.id = char(48+i);		   a.push_back(b);	 }
		}

	}
}



class bsttree { public:	 bsttree *left, *right;	 int val;


bsttree() { left = right = nullptr; val = 0; }
	~bsttree() {}


	void add(bsttree bst, int a) 
	{ if (val == 0) val = a;	
	else if (a > val) { if (right == nullptr) { right = new bstree; }		cout << right->val; }
	else add(*bst.left, a);
	}

	bool empty(bsttree bst) 
	{ if (bst.val!= 0) return false; else return true; }

	void inorder(bsttree bst) 
	{ if (bst.left != nullptr)	inorder(*left);		 
	std::cout << val;		if (bst.right != nullptr)	inorder(*right);
	}

	bool find(bsttree bst, int a) 
	{ if (val == a)		return true;
	else if (right->val == 0) { if (left->val == 0) return false; } }

	void destroy(bsttree& bst) 
	{ bst.~bsttree(); }

	void autofill(bsttree bst) 
	{ add(bst,5);	 add(bst,4);	add(bst,6);		add(bst,3);		add(bst,7);		add(bst,2);		}


};

void exe3() 
{
	bsttree bst;
	
	int num = 1,a;

	
	while (num != 0)
	{

		std::cout << endl << "0 end, 1 add,	 2 if_NULL,	 3 inorder,	4 find, 5 destroy,	6 autofill 10 " << endl;
		std::cin >> num;
			   
		if (num == 1)
		{
			std::cout <<endl<< "enter a number" << endl;
			std::cin >> a;		bst.add(bst, a);
		}

		else if (num== 2)
		{
			if (bst.empty(bst))		
				std::cout << "a tree is empty " << endl;		else std::cout<< "a tree is not empty " << endl;
		}


		else if (num == 3)
		{
			std::cout << endl << " in order: " << endl;		bst.inorder(bst);
		}


		else if (num == 4)
		{
			std::cout << "engter a value " << endl;		 
			std::cin >> a;		
			if(bst.find(bst, a))		
				std::cout << " there's  " << endl;			else std::cout << " there's not " << endl;
		}


		else if (num == 5)
		{
			bst.destroy(bst);		
			std::cout << "deleted" << endl;
		}


		else if (num == 6)
		{
			bst.autofill(bst);		
			std::cout << "filled" << endl;
		}


	}

}






int main()
{
	exe1();
	exe2();
	exe3();
	return 0;
}

