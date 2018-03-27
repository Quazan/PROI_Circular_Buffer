#include <iostream>
#include <string>
using namespace std;

class circular_buffer //bufor cykliczny
{
private:

	const static int SIZE = 4; //rozmiar bufora
	string str[SIZE];	//tablica stringow przechowujaca elementy bufora

	enum fill
	{
		empty,	
		partly,
		full,
	};
	fill state; //3 stany bufora: pusty, cześciowo zapisany, pełny
	int read;	//zmienna przechowujace aktualne miejsce odczytu
	int write;	//zmienna przechowujaca aktualne miejsce zapisu
	string warning; //przechowuje komunikaty o bledach

public:
	circular_buffer();
	int push(string str);	//wstawia pojedynczy element do bufora
	string pop();	//wyjmuje pojedynczy element z bufora
	string peak() const;	//wypisuje pierwszy element do wypisania ale nie usuwa go z bufora
	string remove(int i);	//zdejmuje kokretna liczbe elementow z bufora ale nie wieksza niz jego rozmiar
	int clr();	//resetuje bufor do pierwotnej postaci
	string get_error(); //zwraca bledy ktore wystapily
	const int count() const;	//liczy ile aktualnie jest elementow w buforze
	friend ostream& operator << (ostream&, const circular_buffer &);	//wypisuje cala zawartosc bufora i resetuje jego go do pierwotnej postaci
	friend istream& operator >> (istream&, circular_buffer &);	//wczytuje cala linie elementow oddzielonych spacjami
	friend circular_buffer & operator +=(  circular_buffer &, const circular_buffer &); //wrzuca elementy z jednego bufora do drugiego
};

ostream &operator << (ostream & out, circular_buffer const& buffer);
istream &operator >> (istream & in, circular_buffer & buffer);
circular_buffer & operator +=( circular_buffer &,  const circular_buffer & );
