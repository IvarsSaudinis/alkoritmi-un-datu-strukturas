 /*
  * Papildināt nodarbībā veidoto C++ programmu, kas izveido 
  * stekus A, B un C. Stekos A un B tiek ierakstīti pa 15 gadījuma 
  * skaitļiem. Stekā C ieraksta vispirms visus steka A elementus 
  * un pēc tam - visus steka B  elementus (kopā - stekā C jābūt 30 
  * elementiem).Izdrukāt visu trīs steku vērtības ekrānā.
  * 
  * -- 
  * build with Geany & gcc version 6.3.0 20170516 (Debian 6.3.0-18+deb9u1) 
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Steks
{
	int Data;
	Steks *Next;
};

void Create(Steks* &S);
void Push(Steks* &S, int D);
void Pop(Steks* &S);
int  Top(Steks* &S);
bool isEmpty(Steks* &S);

int main()
{
	Steks *StA; srand(time(0)); int Num;
		
	cout << "Steks A:" << endl;
	Create(StA);
	for (int i=0; i<15; i++)
	{
		Num = rand() % 99 + 1;
		cout << Num << " ";
		Push(StA, Num);	 
	}
	 
	cout << endl << "Steks B:" << endl;
	Steks *StB;
	
	Create(StB);
	for (int i=0; i<15; i++)
	{
		Num = rand() % 99 + 1;
		cout << Num << " ";	 
		Push(StB, Num);	 
	}
	// izveidojam jauno -> iztīram 
	Steks *StC; Create(StC);
	cout << endl << "Steks C:" << endl;
	
	while(!isEmpty(StB)){
		Push(StC,Top(StB)); Pop(StB); 
	} 
	while(!isEmpty(StA)){
		Push(StC,Top(StA)); Pop(StA); 
	} 
	while(!isEmpty(StC)){
		cout << Top(StC) << " "; Pop(StC); 
	} 
	
	return 0;
}

void Create(Steks* &S)
{ S = NULL; }

void Push(Steks* &S, int D)
{
	if (S == NULL)
	{
		S = new Steks;
		S->Data = D; S->Next = NULL;
	}
	else
	{
		Steks *p; p = new Steks;
		p->Data = D; p->Next = S; S = p;
	}
}

void Pop(Steks* &S)
{
	if (S != NULL)
	{
		Steks *p; p = S;
		S = S->Next; 
		delete p;
	}
}

int  Top(Steks* &S)
{
	return (S==NULL) ? -1 : S->Data;
}
bool isEmpty(Steks* &S)
{
	return (S==NULL) ? true : false;
}
