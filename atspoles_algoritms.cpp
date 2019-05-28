/*
 * Using Shuttle Sort algorithm, sort in ascending sort the list of random numbers stored in doubly linked list
 * --
 * build with CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake and little miracle
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Saraksts                     // classic
{
int Dati;
Saraksts *Cits, *Iepr;
};

void ironiski_nosutit_final_psd_maketu_uz_izdruku(struct Saraksts *p )
{
while(p != NULL)
    {
        cout << p->Dati << " ";
p = p->Cits;
}
    cout << endl;
}

int main (){

    srand(time(0));                 // "random" sēkliņas izmešana
Saraksts *H, *p;

cout << "Original: " << endl;

H = new Saraksts;               // tiek izveidots saraksta 1. ieraksts, kas arī tiek automātiski atzīmēts par ierakstu saraksta pirmo punktu
H->Iepr = NULL;                 // atsauce uz iepriekšejo ierakstu ir NULL par cik iepriekšējais nav nemaz iespējams
H->Dati = rand() % 99 + 1;      // aizpildam ar random vērtību 1..99
p = H;                          // atgriež atsauci sākumpunktā

for(int i=0; i<19; i++)         // cikls izpildīsies 0,1,2 ... 18,19 reizes. Kopā 20 reizes
{
        p->Cits = new Saraksts;     // Mainīgā (operanda, šķiet) sadaļā `Cits` piešķiram jauno mainīgo
p->Cits->Iepr = p;          // šī mainīgā Cits vērtības Iepr piešķiršana
p = p->Cits;
p->Dati = rand() % 99 + 1;  // vērtības piešķiršana
}
    p->Cits = NULL;                 // kā arī definējam ieraksta pēdējo vērtību

p = H;                          // Atgriežam atsauci sākotnējā punktā
ironiski_nosutit_final_psd_maketu_uz_izdruku(p); // izdruka ekrānā, loooģiski

p = H;                           // Atgriežam atsauci sākotnējā punktā
do
{
while(p->Dati > p->Cits->Dati )
       {
           swap(p->Cits->Dati , p->Dati);
if(p->Iepr != NULL )
               p = p->Iepr;          // atsauci atmetam uz iepriekšējo vērtību, ja nav NULL
else break;             // ja iepriekš ir break, tad jau laužam ciklu
}
       p = p->Cits;                 // skatāmies nākošo vērtību
}
while(p->Cits!=NULL);           // nodarbinām kamēr nākošā vērtībā nav NULL

cout << "Sorted:" << endl;
p = H;
ironiski_nosutit_final_psd_maketu_uz_izdruku(p); // izvade
return 0;
}
