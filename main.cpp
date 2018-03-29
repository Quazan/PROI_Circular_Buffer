#include <iostream>
#include <string>
#include "buffer.h"

using namespace std;


int main()
{
	circular_buffer bufor;
	circular_buffer pomoc;
	string s;
	string tmp;
	char c = 0;
	int z = 1;
	int a;

	while(z != 0)
	{
		printf("[1] Wstaw \n");
		printf("[2] Wypisz\n");
		printf("[3] Podejrzyj\n");
		printf("[4] Zobacz wszystkie elmenty\n");
		printf("[5] Wyczysc\n");
		printf("[6] Policz\n");
		printf("[7] Zdejmij podana liczbe elementow\n");
		printf("[8] Polacz dwa bufory\n\n");
		printf("[0] Zakoncz\n\n");

		
		cin>>z;
		if(z < 0 || z > 8)
		{
			printf("BLAD WPROWADZANIA DANYCH\n");
			continue;
		}

		getline(cin, s);

		if(s.size() != 0) 
		{
			printf("BLAD WPROWADZENIA DANYCH\n");
			printf("\n\n");
			continue;
		} 

		switch(z)
		{
			case 1:
				printf("Mozesz wpisac kilka elementow oddzielajac je spacja.\n");

				getline(cin, s);
				bufor += s;
				cout<<bufor.get_error();
				break;

			case 2:
				tmp = bufor.pop();

				if(tmp.size() == 0)
				{
					printf("BUFOR PUSTY\n");
				}
				else
				{
					cout<<tmp;
				}
				break;

			case 3:
				tmp = bufor.peak();

				if(tmp.size() == 0)
				{
					printf("BUFOR PUSTY\n");
				}
				else
				{
					cout<<tmp;
				}
				break;

			case 4:
				cout<<bufor;
				break;

			case 5:
				if(bufor.clr())
				{
					printf("BUFOR PUSTY\n");
				}
				else
				{
					printf("BUFOR WYCZYSZCZONY\n");
				}
				break;

			case 6:
				printf("Aktualna ilosc elementow w buforze to ");
				cout<<bufor.count();
				break;

			case 7:
				printf("Podaj liczbe elementow do zdjecia:");
				scanf("%d", &a);

				while(a < 1)
				{
					printf("PODANO ZLA ILOSC\n");
					printf("PODAJ POPRAWNA WARTOSC\n");
					scanf("%d", &a);
				}

				tmp = bufor.remove(a);

				if(tmp.size() != 0)
				{
					cout<<tmp;
				}
				else
				{
					printf("BUFOR PUSTY\n");
				}
				break;

			case 8:
				printf("Wpisz elementy do drugiego bufora: \n");

				cin>>pomoc;
				bufor+=pomoc;
				pomoc.clr();
				
				cout<<bufor;
				cout<<bufor.get_error();
				break;

			case 0:
				return 0;
				break;
		}
		printf("\n\n");
	}
}
