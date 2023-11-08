// kalkulator.cpp: Definuje vstupní bod pro aplikaci.
//

#include "kalkulator.h"
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>


using namespace std;

int main()
{
	char operand = 'c';
	double cislo1 = 0;
	double cislo2 = 0;
	double vysledek = 0;
	char vstup[50];
	
	long long int umocneni = 0;
	double odmocnina = 1 / cislo2;
	
	char pokracovat = 'a';
	
	int jeCislo1 = 0;
	int jeCislo2 = 0;
	
	double pamet[5] = { 0,0,0,0 };
	char pametMisto = 'O';
	int jeMisto = 0;

	printf("\n\033[1;32mVedecka kalkulacka\nVytvoril Michal Herbig a Tomas Kolla\n\n");
	printf("\033[0mPokracujte stisknutim klavesy enter.\n");

	
	printf("\033[0m");

	do
	{

		do
		{

			getchar();
			printf("\n\n\n\033[1;34m---------------------------------------------------");
			printf("\n\nZadejte prvni cislo nebo misto v pameti (A, B, C, D): ");
			scanf("%s", &vstup);


			if (sscanf(vstup, "%lf", &cislo1) == 1) {
					jeCislo1 = 1;
			}
			else if (vstup[0] == 'A' || vstup[0] == 'B' || vstup[0] == 'C' || vstup[0] == 'D') {
				switch (vstup[0])
				{
				case 'A':
					cislo1 = pamet[0];
					break;
				case 'B':
					cislo1 = pamet[1];
					break;
				case 'C':
					cislo1 = pamet[2];
					break;
				case 'D':
					cislo1 = pamet[3];
					break;
				}
			}
			
			
			else {
				printf("\n\033[1;31mMusite zadat cislo\n");
				printf("\033[0m");
				jeCislo1 = 0;
			}

		} while (jeCislo1 == 0);

		do
		{

			vstup[0] = 0;

			printf("\n\nZadejte druhe cislo nebo misto v pameti (A, B, C, D): ");
			scanf("%s", &vstup);


			if (sscanf(vstup, "%lf", &cislo2) == 1) {
				jeCislo2 = 1;
			}
			else if (vstup[0] == 'A' || vstup[0] == 'B' || vstup[0] == 'C' || vstup[0] == 'D') {
				switch (vstup[0])
				{
				case 'A':
					cislo2 = pamet[0];
					break;
				case 'B':
					cislo2 = pamet[1];
					break;
				case 'C':
					cislo2 = pamet[2];
					break;
				case 'D':
					cislo2 = pamet[3];
					break;
				}
			}


			else {
				printf("\n\033[1;31mMusite zadat cislo\n");
				printf("\033[0m");
				jeCislo2 = 0;
				while (getchar() != '\n');
			}

		} while (jeCislo2 == 0);

		printf("\n\n+ - soucet\n- - rozdil\n* - nasobeni\n/ - deleni\n^ - umocneni\nr - odmocneni\n%% - modulo\n\nZadejte pozadovanou operaci: ");
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
		case '%':
			vysledek = fmod(cislo1, cislo2);
			printf("\n\033[1;32mVysledek je: %.3lf", vysledek);
			printf("\033[0m");
			break;
		default:
			printf("\n\033[1;31m%c neni platny znak", operand);
			printf("\033[0m");
			break;

		}
		printf("\n\n\033[1;34m---------------------------------------------------\n");
		printf("\033[0m");
		printf("\n\n\n\nPrejete si provest dalsi vypocet? (a\\n) ");
		scanf(" %c", &pokracovat);


		char ulozitDoPameti = 'o';
		printf("\nPrejete si vysledek ulozit do pameti? (a/n)");
		scanf(" \n%c", &ulozitDoPameti);
		
		if (ulozitDoPameti == 'a') {

			do
			{

				printf("\nVyberte pozadovane misto v pameti (A, B, C, D): ");
				jeMisto = scanf(" %c", &pametMisto);

				switch (pametMisto)
				{
				case 'A':

					pamet[0] = vysledek;
					printf("\n\033[1;32mCislo %.3lf bylo ulozeno do pameti A", vysledek);
					printf("\033[0m");
					jeMisto = 1;
					break;

				case 'B':

					pamet[1] = vysledek;
					printf("\n\033[1;32mCislo %.3lf bylo ulozeno do pameti B", vysledek);
					printf("\033[0m");
					jeMisto = 1;
					break;

				case 'C':

					pamet[2] = vysledek;
					printf("\n\033[1;32mCislo %.3lf bylo ulozeno do pameti C", vysledek);
					printf("\033[0m");
					jeMisto = 1;
					break;

				case 'D':

					pamet[3] = vysledek;
					printf("\n\033[1;32mCislo %.3lf bylo ulozeno do pameti D", vysledek);
					printf("\033[0m");
					jeMisto = 1;
					break;

				default:
					printf("\n\033[1;31m%c neni platny znak", pametMisto);
					printf("\033[0m");
					jeMisto = 0;
					break;
				}

			} while (jeMisto == 0);

		}


	} while (pokracovat == 'a');
	
	return 0;
}
