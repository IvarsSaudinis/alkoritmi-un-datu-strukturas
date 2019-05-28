#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int compared =0, swaped =0;

struct BinKoks
{
BinKoks * Kreisais;
int Dati;
BinKoks * Labais;
};
void HeapSort(int Masivs[], int N);
void Solis(int Masivs[], int Sencis, int N);

int main()
{
int Dati[21]; Dati[0] = -1;
srand(time(0));
for (int i=1; i<21; i++)
{
Dati[i] = rand() % 99 + 1;
cout << Dati[i] << " ";
}
cout << endl;

HeapSort(Dati, 20);

for (int i=1; i<21; i++)
cout << Dati[i] << " ";

cout << endl << "Salidzinasanu skaits: " << compared;
cout << endl << "Samainisanu skaits: " << swaped;

return 0; 
}

void HeapSort(int Masivs[], int N)
{
int Y = N/2;
// 1.faze:
while (Y > 0)
{
Solis(Masivs, Y, N);
Y--;
}
// 2.faze:
Y = N;
while (Y > 0)
{
int Pag = Masivs[1];
Masivs[1] = Masivs[Y];
Masivs[Y] = Pag;
Y--;
swaped++;
Solis(Masivs, 1, Y);
}
} // HeapSort

void Solis(int Masivs[], int Sencis, int N)
{ // Sakarto apakskoku ar sakni Sencis par piramidu
int Kaste = Masivs[Sencis];
int Berns = Sencis * 2;
int Nagla = Sencis;
bool Atrasts = false;
while ( (!Atrasts) && (Berns <= N))
{
if (Berns < N)
if (Masivs[Berns+1] > Masivs[Berns]) 
{
compared++;
Berns++;
}
if (Masivs[Berns] > Kaste)
{
Masivs[Nagla] = Masivs[Berns];
Nagla = Berns; Berns = Berns*2;
compared++;
swaped++;
}
else Atrasts = true;
} // while ( (!Atrasts) && (Berns <= N))
Masivs[Nagla] = Kaste;
} // void Solis
