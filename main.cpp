#include <iostream>
#include <string>
#include "buffer.h"

using namespace std;


int main()
{
	circular_buffer bufor;
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
		printf("[7] Zdejmij podana liczbe elementow\n\n");
		printf("[0] Zakoncz\n\n");

		
		cin>>z;
		if(z < 0 || z > 7)
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
				cin>>bufor;
				break;

			case 2:
				cout<<bufor.pop();
				break;

			case 3:
				cout<<bufor.peak();
				break;

			case 4:
				cout<<bufor;
				break;

			case 5:
				bufor.clr();
				break;

			case 6:
				cout<<bufor.count();
				break;

			case 7:
				printf("Podaj liczbe elementow do zdjecia:");
				scanf("%d", &a);
				bufor.remove(a);
				break;

			case 0:
				return 0;
				break;
		}
		printf("\n\n");
	}
}
