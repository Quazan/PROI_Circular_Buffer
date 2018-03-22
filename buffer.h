#include <iostream>
#include <string>
using namespace std;

class circular_buffer //bufor cykliczny
{
private:

	const static int SIZE = 10; //rozmiar bufora
	string str[SIZE];	//tablica stringow przechowujaca elementy bufora

	enum fill
	{
		empty,	
		partly,
		full,
	};
	fill state; 
			//3 stany bufora: pusty, cześciowo zapisany, pełny
	int read;	//zmienna przechowujace aktualne miejsce odczytu
	int write;	//zmienna przechowujaca aktualne miejsce zapisu

public:
	circular_buffer();
	void push(string str);	//wstawia pojedynczy element do bufora
	string pop();	//wyjmuje pojedynczy element z bufora
	string peak() const;	//wypisuje pierwszy element do wypisania ale nie usuwa go z bufora
	void remove(int i);	//zdejmuje kokretna liczbe elementow z bufora ale nie wieksza niz jego rozmiar
	void clr();	//resetuje bufor do pierwotnej postaci
	const int count() const;	//liczy ile aktualnie jest elementow w buforze
	friend ostream& operator<< (ostream&, circular_buffer const&);	//wypisuje cala zawartosc bufora i resetuje jego go do pierwotnej postaci
	friend istream& operator>> (istream&, circular_buffer &);	//wczytuje cala linie elementow oddzielonych spacjami
};

ostream &operator<< (ostream & out, circular_buffer const& buffer);
istream &operator>> (istream & in, circular_buffer & buffer);
