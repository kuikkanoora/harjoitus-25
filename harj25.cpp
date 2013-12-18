/*************************************************************************************************************************************************************
*Tehtävä: Harjoitus25
*Tekijä: Noora Kuikka
*PVM: 10.12.2013
*Kuvaus:
*Harjoitus 25 (Palautus vko 51)
*
*Muuta harjoituksen 24 toiminnallisuutta niin, etta
*varaat henkilötiedoille tilan dynaamisesti (max 10 hlo).
*Muuta valikko alla olevan esimerkin mukaiseksi ja toteuta valikossa
*näkyvät toiminnot.
*
*VALIKKO
*0 Lopeta
*1 Lisaa henkilo
*2 Nayta henkilo
*3 Nayta kaikki henkilot
*4 Poista henkilon tiedot
*
*Versio 1.0 H4719 10.12.2013
**************************************************************************************************************************************************************/

#include <iostream>
using namespace std;

struct PEOPLE
{
	char name[20];
	double journey;
	int size;
};

const int MAX_ARRAY = 10;

int Menu(void);
void PrintAll(PEOPLE per[], int num);
void AddPerson(PEOPLE [], int *num);
void PrintPerson(PEOPLE num[]);
void RemovePerson(PEOPLE per[], int *per_num);

int main()
{
	int choice = 0;
	int num = 0;
	bool cont = true;
	PEOPLE* per = new PEOPLE [MAX_ARRAY];

	do
	{
		cout << "\nThe number of people in the register: " << num << endl;
		cout << "Max. 10." << endl;
		choice = Menu();
		cout << endl;

		switch (choice)
		{
		case 0:
			{
				cout << "\nExiting program...\n";
				cont = false;
				break;
			}
		case 1:
			{
			    if(num < 10)
				{
					AddPerson(per, &num);
				}
                else
				{
					cout << "You have reached the maximum amount of people this register can store." << endl;
				}
				break;
			}
		case 2:
			{
				PrintPerson(per);
				break;
			}
		case 3:
			{
				PrintAll(per, num);
				break;
			}
		case 4:
			{
				RemovePerson(per, &num);
				break;
			}
		default:
			{
				cout << "\nIncorrect input. Enter either '0', '1', '2' or '3'.\n";
				break;
			}
		}
	}

	while (cont == true);
	delete [] per;
}

int Menu(void)
{
	int choice;

	cout << "\n*MENU*\n";
	cout << "\n0. Exit\n";
	cout << "\n1. Add person to register\n";
	cout << "\n2. Print person in register\n";
	cout << "\n3. Print all people in register\n";
	cout << "\n4. Remove a person from the register\n" << endl;
	cin >> choice;

	return choice;
}

void PrintAll(PEOPLE per[], int num)
{
	cout << "Listing people..." << endl;
	for (int ind = 0; (ind < num); ind++)
	{
		cout << "\nName: " << per[ind].name << endl;
		cout << "Distance: " << per[ind].journey << "km" << endl; 
		cout << "Hat size: " << per[ind].size << endl;
		cout << endl;
	}
}

void AddPerson(PEOPLE p_per[], int *per_num)
{
	cout << "\nEnter the first name:\n";
	cin >> p_per[*per_num].name;
	cout << "\nEnter the distance to school:\n";
	cin >> p_per[*per_num].journey;
	cout << "\nEnter the hat size:\n";
	cin >> p_per[*per_num].size;

	(*per_num)++;
}

void PrintPerson(PEOPLE p_per[])
{
	int numb;
	cout << "Enter a number:" << endl;
	cin >> numb;
	if (numb > 10)
	{
		cout << "Incorrect input, the maximum number of people in the register is 10." << endl;
	}
	else
	{
		cout << "Name: " << p_per[numb-1].name << endl;
		cout << "Distance: " << p_per[numb-1].journey << "km" << endl;
		cout << "Hat size: " << p_per[numb-1].size << endl;
	}
}

void RemovePerson(PEOPLE p_per[], int *per_num)
{
	int numb;

	cout << "Enter the number of the person you wish to delete from the register: " << endl;
	cin >> numb;

	*p_per[numb-1].name = NULL;
	p_per[numb-1].journey = 0;
	p_per[numb-1].size = 0;

	for(numb; numb <= *per_num; numb++)
	{
		p_per[numb-1] = p_per[numb];
	}

	(*per_num)--;
}

