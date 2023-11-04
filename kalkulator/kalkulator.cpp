// kalkulator.cpp: Definuje vstupní bod pro aplikaci.
//

#include "kalkulator.h"
#include <ctype.h>
#include <stdio.h>
#include <math.h>


using namespace std;

int main()
{
	char operand = 'c';
	double cislo1 = 0;
	double cislo2 = 0;
	double vysledek = 0;
	long long int umocneni = 0;
	double odmocnina = 1 / cislo2;
	char pokracovat = 'a';
	int jeCislo1 = 0;
	int jeCislo2 = 0;

	printf("\n\033[1;32mVedecka kalkulacka\nVytvoril Michal Herbig a Tomas Kolla\n\n\033[0mPokracujte stisknutim libovolne klavesy\n");
	printf("\033[0m");

	do
	{

		do
		{
			
			getchar();
			printf("\nZadejte prvni cislo: ");
			jeCislo1 = scanf("%lf", &cislo1);

			
			if (jeCislo1 == 1) {
				printf("");
			}
			else {
				printf("\n\033[1;31mMusite zadat cislo\n");
				printf("\033[0m");
				jeCislo1 = 0;
			}
		
		} while (jeCislo1 == 0);

		do 
		{

			printf("\nZadejte druhe cislo: ");
			jeCislo2 = scanf("%lf", &cislo2);

			if (jeCislo2 == 1) {
				printf("");
			}
			else {
				printf("\n\033[1;31mMusite zadat cislo\n");
				printf("\033[0m");
				jeCislo2 = 0;
				while (getchar() != '\n');
			}

		} while (jeCislo2 == 0);

		printf("\nZadejte pozadovanou operaci: (+ - * / ^ r) ");
		scanf(" %c", &operand);

		switch (operand)
		{

		case '+':
			vysledek = cislo1 + cislo2;
			printf("\n\033[1;32mVysledek je: %.3lf", vysledek);
			printf("\033[0m");
			break;

		case '-':
			vysledek = cislo1 - cislo2;
			printf("\n\033[1;32mVysledek je: %.3lf", vysledek);
			printf("\033[0m");
			break;

		case '*':
			vysledek = cislo1 * cislo2;
			printf("\n\033[1;32mVysledek je: %.3lf", vysledek);
			printf("\033[0m");
			break;
		case '/':
			vysledek = cislo1 / cislo2;
			printf("\n\033[1;32mVysledek je: %.3lf", vysledek);
			printf("\033[0m");
			break;
		case '^':
			umocneni = pow(cislo1, cislo2);
			printf("\n\033[1;32mVysledek je: %lli", umocneni);
			printf("\033[0m");
			break;
		case 'r':
			vysledek = pow(cislo1, 1 / cislo2);
			printf("\n\033[1;32mVysledek je: %.3lf", vysledek);
			printf("\033[0m");
			break;
		default:
			printf("\n\033[1;31m%c neni platny znak", operand);
			printf("\033[0m");
			break;

		}
		printf("\n\nPrejete si provest dalsi vypocet? (a\\n) ");
		scanf(" %c", &pokracovat);
	} while (pokracovat == 'a');
	
	return 0;
}
