#include "buffer.h"
#include <iostream>
#include <string>
using namespace std;

circular_buffer :: circular_buffer()
{
	state = empty;
	read = 0;
	write = 0;
}

void circular_buffer::push(string s)
{
	if(state == full)
	{
		printf("UWAGA! NADPISANIE komorki nr %d , element nadpisany to: ", write);
		cout<<str[read]<<endl;
		if(read == SIZE-1) read = 0;
		else read++;
	}

	str[write] = s;

	if(write == SIZE-1) write = 0;
	else write++;

	if(write == read) state = full;
	else state = partly;
}

string circular_buffer::peak() const
{
	if(state == empty)
	{
		printf("PUSTY BUFOR \n");
		return "";
	}
	else
	{
		printf("Pierwszy element w buforze to:\n");
		return str[read];
	}
}

string circular_buffer::pop()
{
	string temp;

	if(state == empty)
	{
		printf("PUSTY BUFOR\n");
		return "";
	}
	else
	{
		temp = str[read];
		str[read].clear();

		if(read == SIZE-1) read = 0;
		else read++;

		if(state == full) state = partly;
		else if(state == partly && read == write) state = empty;

		printf("Zdjety element to: ");
		return temp;
	}
}


void circular_buffer::remove(int i)
{
	if(state == empty)
	{
		printf("BUFOR PUSTY\n");
	}
	
	while((i < 1 || i > SIZE) && state != empty)
	{
		printf("PODANO ZLA ILOSC\n");
		printf("PODAJ POPRAWNA WARTOSC\n");
		scanf("%d", &i);
	}

	while(state != empty && i > 0)
	{
		cout<<str[read]<<endl;
		str[read].clear();

		if(read == SIZE-1) read = 0;
		else read++;

		i--;

		if(state == full) state = partly;
		else if(state == partly && read == write) state = empty;
	}
}

void circular_buffer::clr()
{
	if(state == empty)
	{
		printf("BUFOR PUSTY\n");
	}
	else
	{
		printf("Bufor wyczyszczony");
		for(int i = 1; i < SIZE; i++)
		{
			str[i].clear();
		}

		read = 0;
		write = 0;
		state = empty;
	}
}

const int circular_buffer::count() const
{
	printf("Aktualna ilosc elementow w buforze to ");

	if(write >= read && state != empty) return (write - read);
	else if(state == full) return SIZE;
	else return SIZE - abs(write-read);
}

ostream& operator<< (ostream& out, circular_buffer const& buffer)
{
	int r, w, stan;
	r = buffer.read;
	w = buffer.write;
	stan = buffer.state;

	if(stan == 0)
	{
		out<<"BUFOR PUSTY"<<endl;
	}
	else
	{
		out<<"Zawartosc bufora:"<<endl;
	}

	while(stan != 0)
	{

		out<<buffer.str[r]<<endl;
		if(r == buffer.SIZE-1) r = 0;
		else r++;

		if(r == w) stan = 0;
	}
	
	return out;
}

istream &operator>> (istream & in, circular_buffer & buffer)
{
	string s;
	string tmp;

	getline(in, s);
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 32)
		{
			if(tmp.size() != 0)
			{
				buffer.push(tmp);
				tmp.clear();
			}
		}
		else
		{
			tmp += s[i];
		}
	}
	if(tmp.size() != 0)
	{
		buffer.push(tmp);
		tmp.clear();
	}
	return in;
}
