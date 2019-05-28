/* UZDEVUMS UZRAKSTITS IZMANTOJOT VEKTORUS :(

a) Uzrakstīt C++ programmu, kas izveido 20 elementu sarakstu Pirmais, kur katrs elements ir
 pseidogadījumu vesels skaitlis (starp 1 un 99). Izvadīt ekrānā saraksta Pirmais vērtības.
b) Pēc tam izveidot sakārtotu sarakstu Otrais, kurā
 ieraksta saraksta Pirmais visus pāra skaitļus. Izvadīt ekrānā saraksta Otrais vērtības.
c) No saraksta Pirmais izdzēst vērtības, kas dalās ar 3 bez atlikuma. Izvadīt ekrānā dzēstās
 vērtības un saraksta Pirmais atlikušās vērtības.
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main() {

vector <int> Pirmais;
vector <int>::iterator it;

int Skaitlis;
srand(time(0));

//  a) daļa uzdeuvmam
cout << "`Pirmais` izvade: " << endl;
Skaitlis = rand () % 99 + 1; cout << Skaitlis << " ";
Pirmais.push_back(Skaitlis); // push_back -> pievienot elementu saraksta beigaas;

for(int i=0; i<19; i++)
    {
        Skaitlis = rand () % 99 + 1; cout << Skaitlis << " ";

for(it = Pirmais.begin(); it < Pirmais.end(); it++)
        {
if(Skaitlis<*it)
            {
                Pirmais.insert(it, Skaitlis);
break;
}
        }
if(it == Pirmais.end()) Pirmais.push_back(Skaitlis);
}

// b daļa uzdevumam
cout << endl  << endl  << "Otrais cikls izvada para skaitlus: " << endl;
vector <int> Otrais;
for(  it = Pirmais.begin(); it<Pirmais.end(); it++) {
if(*it % 2 == 0) // Paara skaitli
{
            Otrais.push_back(*it);
cout  << *it << " ";
}
    }

// c) daļa uzdevumam
cout << endl   << endl  << "Tresais cikls dzeesto ierakstu vertibas: " << endl;
for(  it = Pirmais.begin(); it<Pirmais.end(); it++) {

if(*it % 3 == 0)
        {
            cout << *it << " "; // izvadām vērtību, kas dalās atlikumā bez trīs;
Pirmais.erase(it); // izdzēšam vērtību
}
    }
// izvadam Pirmais sarakstu
cout << endl <<  endl  << "cikls izvada  `Pirmais` palikusos skaitlus: " << endl;
for(  it = Pirmais.begin(); it<Pirmais.end(); it++) {
        cout << *it << " ";
}
    cout << endl << endl << "Programmas laimigas beigas! " <<  endl;

return 0;
}
