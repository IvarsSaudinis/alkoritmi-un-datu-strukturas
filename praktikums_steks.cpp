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

// majasdarba funkcijas
int Lielums (Steks * &S);
void Druka (Steks * &S);
void ReversaDruka (Steks * &S);
int Ntais (Steks* &S, int N); 

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
	  
	 cout << endl;
	 cout << "Lielums: " << Lielums(StA) << endl;
	
	 cout <<  "Druka: "; Druka(StA);  cout << endl;
	 cout <<  "ReversaDruka: "; ReversaDruka(StA); cout << endl;
	 cout <<  "4. elements: " <<  Ntais(StA, 4);
	  
	return 0;
}

int Lielums (Steks* &S)
{
	Steks *p;
	p = S;
	int skaits=0;
	while( p != NULL)
	{		
		p = p->Next; 
		skaits++; 
	} 
	return skaits;
}

void Druka (Steks * &S)
{
	Steks *p;
	p = S;
	while( p != NULL)
	{
		cout << p->Data << " ";
		p = p->Next; 
	}
}

void ReversaDruka (Steks * &S)
{
	Steks *p, *c;
	p = S;
	c = new Steks;
	while( p != NULL)
	{
		Push(c,p->Data);
		p = p->Next; 
	}
	  
	  Druka(c);
	
}

int Ntais (Steks* &S, int N)
{
	Steks *p; p = S;
	
	int c = 0;
	while( p != NULL)
	{
		if(c==N)
		{
			return p->Data;
		}
		p = p->Next; 
		c++;
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
