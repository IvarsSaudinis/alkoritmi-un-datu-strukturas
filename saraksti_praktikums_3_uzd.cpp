/*
 * Uzrakstīt C++ programmu, kas izveido divus saistītos sarakstus
 * L1 un L2, kur katram no tiem elementu skaitu nosaka kā gadījuma 
 * skaitli (starp 20 un 50). No abiem sarakstiem izveidot sarakstu L3 
 * šādā veidā – saraksta L1 pirmais elements, saraksta L2 pirmais 
 * elements,  * saraksta L1 otrais elements, saraksta L2 otrais 
 * elements, u.t.t. Izdrukāt visu trīs sarakstu elementus..
 * 
 * --
 * build with Geany & gcc version 6.3.0 20170516 (Debian 6.3.0-18+deb9u1) 
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Saraksts                     // classic
{
    int Dati;
    Saraksts *Cits;
};

void izdruka(struct Saraksts *p )
{
	int c=0;
    while(p != NULL)
    {
        cout << p->Dati << " ";
        p = p->Cits;
        c++;
    }
    cout << "[" << c << "]" << endl;
}

int main (){

    srand(time(0));                 // "random" sēkliņas izmešana
    Saraksts  *p, *L1, *L2, *L3, *t1, *t2;

	// L1
    cout << "Original L1: " << endl;
    L1 = new Saraksts;
    L1->Dati = rand() % 99 + 1;
    p = L1;
    for(int i=0; i < rand() %21 + 31; i++)
    {
        p->Cits = new Saraksts;
        p = p->Cits;
        p->Dati = rand() % 99 + 1;
    }
    p->Cits = NULL;

    p = L1;
    izdruka(p);

	// L2 
    cout << "Original L2: " << endl;
    L2 = new Saraksts;
    L2->Dati = rand() % 99 + 1;
    p = L2;
    for(int i=0; i < rand() % 21 + 31; i++)
    {
        p->Cits = new Saraksts;
        p = p->Cits;
        p->Dati = rand() % 99 + 1;
    }
    p->Cits = NULL;

    p = L2;
    izdruka(p);
    
     // temp
	t1 = L1;
	t2 = L2; 
	
    // L3
    cout << "Created L3: " << endl;
    L3 = new Saraksts;
    L3->Dati = t1->Dati; // iestatām pirmo vērtību
	
	t1= t1->Cits;
	
    p = L3;
   
    while(t1!=NULL || t2!=NULL ) // kapājam kamēr L1 un L2 nesasniedz beigas
    {
		 
			if(t2!=NULL)
			{
				p->Cits = new Saraksts;
				p->Cits->Dati = t2->Dati;
				p= p->Cits;
				t2 = t2->Cits;  
			}
		  
		 
		 
			
			if(t1!=NULL)
			{
				p->Cits = new Saraksts;
				p->Cits->Dati = t1->Dati;
				p= p->Cits;
				t1 = t1->Cits;  
			}
	 
	  	 
	}
 
    p = L3;
    izdruka(p);
    
    return 0;
}
