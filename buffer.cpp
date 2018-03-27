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

int circular_buffer::push(string s)
{
	int overflow;

	if(state == full)
	{
		warning += "UWAGA! NADPISANIE komorki nr ";
		warning += write + 48;
		warning += " , element nadpisany to: ";
		warning += str[read];
		warning += "\n";

		str[read].clear();

		overflow = 1;

		if(read == SIZE-1) read = 0;
		else read++;
	}

	str[write] = s;

	if(write == SIZE-1) write = 0;
	else write++;

	if(write == read) state = full;
	else state = partly;

	return overflow;
}

string circular_buffer::peak() const
{
	if(state == empty)
	{
		return "";
	}
	else
	{
		return str[read];
	}
}

string circular_buffer::pop()
{
	string temp;

	if(state == empty)
	{
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

		return temp;
	}
}

string circular_buffer::remove(int i)
{
	string s;

	if(state == empty)
	{
		return "";
	}
	
	while(state != empty && i > 0)
	{
		s += pop();
		s += "\n";
		i--;
	}

	return s;
}

int circular_buffer::clr()
{
	if(state == empty)
	{
		return 1;
	}
	else
	{
		for(int i = 1; i < SIZE; i++)
		{
			str[i].clear();
		}

		read = 0;
		write = 0;
		state = empty;

		return 0;
	}
}

const int circular_buffer::count() const
{
	if(write > read && state != empty) return (write - read);
	else if(state == full) return SIZE;
	else if(state == empty) return 0;
	else return SIZE - abs(write-read);
}

string circular_buffer::get_error()
{
	string tmp;

	tmp = warning;
	warning.clear();

	return tmp;
}

ostream& operator << (ostream& out, circular_buffer const& buffer)
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
		out<<"\nZawartosc bufora:"<<endl;
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

istream &operator >> (istream & in, circular_buffer & buffer)
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

circular_buffer & operator += (circular_buffer & left, const circular_buffer & right)
{
	int var = right.count();
	int r = right.read;
	int size = right.SIZE;
	string tmp;

	for(int i = 1; i <= var; i++)
	{
		tmp = right.str[r];
		left.push(tmp);

		if(r == size-1) r = 0;
		else r++;
	}

	return left;
}