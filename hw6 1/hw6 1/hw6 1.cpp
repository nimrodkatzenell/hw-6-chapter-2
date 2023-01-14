#include <iostream>
#include <string.h>
using namespace std;
#define MAX_STR 20
#define SIZE 10
struct Event
{
	char title[MAX_STR]; // the name of the event
	char place[MAX_STR]; // the place where the event took place
	int year;

};
struct Sportsman
{

	int id; // id number
	char pName[MAX_STR]; // private name
	char fName[MAX_STR]; // family name
	bool gender; // the gender of the sportsman, true - woman, false – man
	int numEvents; // number of events the sportsman played
	Event* events; // array of events where the sportsman played
};

bool addSportsman(Sportsman sport[], int size, int *num,int add);
int countEvent(char eventname[], int eventyear, Sportsman sport[], int size);
bool checkWomenEvent(char eventName[], int eventyear, Sportsman sport[], int size);
void compareCountries(Sportsman sport[], int size);


int main()
{
	/*Sportsman sport[10];
	Event a = { "a","london",1999 };
	Event b = { "b","qwer",1 };
	Event c = { "c","london",1999 };
	Event d = { "d","qwer",1 };
	Event e = { "e","no",19 };

	sport[0].events = &a;
	sport[1].events = &b;
	sport[2].events = &c;
	sport[3].events = &d;
	sport[4].events = &d;

	compareCountries(sport, 5);*/
	int num = 0;
	Event a = { "olimpics","london",1999 };
	Event b = { "NBA","USA",2020 };
	Event c = { "tennis","london",1999 };
	Sportsman sport[10];
	addSportsman(sport, SIZE, &num,5);
	for (int i = 0; i < 5; i++)
	{
		cout << sport[i].pName << endl;
		cout << sport[i].fName << endl;
		cout << sport[i].gender << endl;
		cout << sport[i].numEvents << endl;
	}
}


bool addSportsman(Sportsman sport[], int size, int *num,int add)
{
	
	if (*num+add >=size)
	{
		cout << "\nsorry not enough space!";
		return false;
	}
		
	for (int i = *num; i < *num + add; i++)
	{
		cout << "\nplease enter id: ";
		cin >> sport[i].id;
		for (int j = 0; j < i; j++)
		{
			if (sport[i].id == sport[j].id)
			{
				cout << "allready inside";
				sport[i].id = NULL;
				return false;
			}
		}
		cout << "\nplease enter private name: ";
		cin >> sport[i].pName;
		cout << "\nplease enter family name: ";
		cin >> sport[i].fName;
		cout << "\nplease enter gender 1=female 0=male : ";
		cin >> sport[i].gender;
		cout << "\nplease enter number of events : ";
		cin >> sport[i].numEvents;
	}
	*num += add;


}


void compareCountries(Sportsman sport[], int size)
{
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size-1 ; j++)
		{
			if (flag&&strcmp(sport[i].events->place, sport[j + 1].events->place) == 0 && strcmp(sport[i].events->title, sport[j + 1].events->title) != 0 && sport[i].events->year == sport[j + 1].events->year)
			{
				cout << "\nthe name of the event " << sport[i].events->title;
				cout << "\nthe name of the other event " << sport[j + 1].events->title;
				cout << "\nthe year of the event " << sport[i].events->year;
				flag = false;
			}
		}
		cout << endl;
		flag = true;
	}

}

bool checkWomenEvent(char eventName[], int eventyear, Sportsman sport[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		cout << eventName << endl;
		cout << sport[i].events->title << endl;
		cout << strcmp(sport[i].events->title, eventName);
		if (sport[i].gender == 1 && strcmp(sport[i].events->title, eventName) == 0 && sport[i].events->year == eventyear)
		{
			sum++;
		}
		if (sum >= 2)
		{
			return true;
		}
	}
	return false;
}

int countEvent(char eventname[], int eventyear, Sportsman sport[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(sport[i].events->title) == *eventname && sport[i].events->year == eventyear)
		{
			sum++;
		}
	}
	return sum;

}
