#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <regex>

using namespace std;

int randomInt(int min, int max) {
	static std::default_random_engine e{};
	std::uniform_int_distribution<int > d(min, max);
	return d(e);
}

const std::string phys_data(R"(
Speed:	366
Mass:	35
Point: 50 70
Speed:	378
Mass:	32
Point: 25 35
Speed:	400
Mass:	30
Point: 23 16)");


//zad1

void zadanie1()
{
	std::regex p_regex("Point:[[:space:]]*([[:digit:]]*)[[:space:]]*([[:digit:]]*)");
	std::smatch sm;

	auto data = phys_data;
	while (std::regex_search(data, sm, p_regex) ) 
	{
		std::cout << "Full Match> " << sm[0] << '\n';
		data = sm.suffix(); // zastępuje wartość zmiennej 'data' tym co nie zostało jeszcze przeszukane
	}


}


struct Point
{
	string x, y;
};

void fill(vector<Point>&po){

	Point p;
	std::regex p_regex("Point:[[:space:]]*([[:digit:]]*)[[:space:]]*([[:digit:]]*)");
	std::smatch sm;

	auto data = phys_data;
	while (std::regex_search(data, sm, p_regex))
	{

		p.x = sm[1];
		p.y = sm[2];
		data = sm.suffix();

		po.push_back(p);
	}

	}


//zad2
void zadanie2()
{
	vector<Point>po;
	fill(po);
	for(auto e:po )
	cout << e.x<<"  "<<e.y<<endl;
}




//zad3

std::vector<std::string> parse_titles(std::string data) {

	std::vector<std::string> titles; 
	std::regex title_regex{ "img scr=\"([:digit:])\"  title=\"([[:alnum:][:space:]]*)\"" };

	std::smatch title_match;
	while (std::regex_search(data, title_match, title_regex)) {
		titles.push_back(title_match[2]);
		cout <<"jest "<< title_match[0] << endl;
		data = title_match.suffix();
	}
	return titles;
}
//----------------------------------------------------------------------
const std::string cats_file = "cats.html";

struct Cat {
	std::string url;
	std::string title;
	std::string img_url;
};

std::vector<std::string> parse_titles_it(const std::string &data) {

	std::vector<std::string> titles;
	std::regex title_regex{ "title=\"([[:alnum:][:space:]]*)\"" };

	auto titles_begin = std::sregex_iterator(data.begin(), data.end(), title_regex);
	std::transform(titles_begin, {}, std::back_inserter(titles),
		[](const std::smatch &sm) { return sm[1]; });

	return titles;
}
std::vector<Cat> parse_cats(std::string cats_data) {

	std::vector<Cat> cats;

	std::regex title_regex{ "img scr=\"([:digit:])\"  title=\"([[:alnum:][:space:]]*)\"" };

	std::smatch title_match;
	while (std::regex_search(cats_data, title_match, title_regex)) {
		cats.push_back(title_match[2]);
		cout << "jest " << title_match[0] << endl;
		cats_data = title_match.suffix();
	}

	return cats;
}

void print(const Cat &cat) {
	std::cout << "Url: " << cat.url << ", title: " << cat.title
		<< ", img_url: " << cat.img_url << '\n';
}

void print(const std::vector<Cat>& cats) {
	for (const auto& cat : cats) {
		print(cat);
	}
}
void print(const std::vector<std::string>& titles) {
	for (const auto& title : titles) {
		
		std::cout << "Title: " << title << '\n';
	}
}

std::string load_cats() {
	std::fstream stream_of_cats{ cats_file };
	std::string cats_data{ std::istreambuf_iterator<char>(stream_of_cats),{} };
	return cats_data;
}

void zadanie3() {

	// poniżej znajdują się wywołania dwóch różnych implementacji dopasowywania wzorców.
	// wyciągają one wszystkie atrybuty 'title', zarówno ze znaczników <a> jak i <img>
	// Dostosuj wyrażenia regularne,tak, wyciągać tytuł tylko ze znacznika 'img'.

	const auto cats_data = load_cats();
	{
		auto titles = parse_titles(cats_data);
		print(titles);
	}
	/*{
		auto titles = parse_titles_it(cats_data);
		print(titles);
	}*/

}


//zad4

void zadanie4() {

	// zaimplementuj funkcję parse_cats wypełniającą kontener obiektów typu Cat.
	// Struktury Cat uzupełnij w następujący sposób:
	// url <- zawartość atrybutu href znacznika <a>
	// title <- zawartość atrybutu title znacznika <img>
	// img_url <- zawartość atrybutu src znacznika <img>

	const auto cats_data = load_cats();
	std::vector<Cat> cats = parse_cats(cats_data);
	print(cats);
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
			cout << "zad 1 " << endl;
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

			cout << "zad 3 " << endl;
			zadanie3();


			cout << endl;
			break;
		}

		case 4:
		{

			cout << "zad 4 " << endl;
			zadanie4();


			cout << endl;
			break;
		}

		default:
			cout << " zly numer ";
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
					cout << " zly numer ";
		}
		cout << endl;
	} while (b != 1);
	cout << " Do zobaczenia! " << endl;
	return 0;
}





