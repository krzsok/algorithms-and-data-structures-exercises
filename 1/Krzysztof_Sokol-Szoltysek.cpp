using namespace std;

#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<iostream>

const int maxZ = 100; // maksymalna ilosc testow
const int maxSize = 10; // maksymalny rozmiar pojedynczego testu
const int maxValue = 1000; // maksymalna wartosc liczby z ciagu liczb


void Bubblesort(int tab[],int n)
{
  int pom;
 
  for(int i=0;i<n;i++)
    for(int j=0;j<n-i-1;j++) //pêtla wewnêtrzna
    if(tab[j]>tab[j+1])
    {
      //zamiana miejscami
      pom = tab[j];
      tab[j] = tab[j+1];
      tab[j+1] = pom;
    }
}

void Insertionsort(int n, int *tab)
{
     int pom, j;
     for(int i=1; i<n; i++)
     {
             //wstawienie elementu w odpowiednie miejsce
             pom = tab[i]; //ten element bêdzie wstawiony w odpowiednie miejsce
             j = i-1;
 
             //przesuwanie elementów wiêkszych od pom
             while(j>=0 && tab[j]>pom) 
             {
                        tab[j+1] = tab[j]; //przesuwanie elementów
                        --j;
             }
             tab[j+1] = pom; //wstawienie pom w odpowiednie miejsce
     }     
}

void scal(int tab[], int lewy, int srodek, int prawy) 
{
  int pom[maxSize];
  int i, j;
 
  //zapisujemy lew¹ czêsæ podtablicy w tablicy pomocniczej
  for(i = srodek + 1; i>lewy; i--) 
    pom[i-1] = tab[i-1]; 
 
  //zapisujemy praw¹ czêsæ podtablicy w tablicy pomocniczej
  for(j = srodek; j<prawy; j++) 
    pom[prawy+srodek-j] = tab[j+1]; 
 
  //scalenie dwóch podtablic pomocniczych i zapisanie ich 
  //we w³asciwej tablicy
  for(int k=lewy;k<=prawy;k++) 
    if(pom[j]<pom[i])
      tab[k] = pom[j--];
    else
      tab[k] = pom[i++];
}
 
 
void sortowanie_przez_scalanie(int tab[],int lewy, int prawy)
{
  //gdy mamy jeden element, to jest on ju¿ posortowany
  if(prawy<=lewy) return; 
 
  //znajdujemy srodek podtablicy
  int srodek = (prawy+lewy)/2;
 
  //dzielimy tablice na czêsæ lew¹ i prawa
  sortowanie_przez_scalanie(tab, lewy, srodek); 
  sortowanie_przez_scalanie(tab, srodek+1, prawy);
 
  //scalamy dwie ju¿ posortowane tablice
  scal(tab, lewy, srodek, prawy);
}
 
 
void countingsort(int A[], int B[], int k, int rozmiar)
{
     

int i;
int *C = new int [k+1]; // utworzenie tablicy na statystyki; wszystkie liczby w tablicy sa nie wieksze od k, a C[i] okresla ile razy wystapila liczb i
for (i = 0; i <= k; i++) // zerowanie tablicy pomocniczej
C[i] = 0;
for (i = 0; i < rozmiar; i++)
C[(A[i])]++;
// C[i] zawiera teraz liczbe wystapien liczby i w ciagu wejsciowym
for (i = 1; i <= k; i++)
C[i] += C[i-1];
// C[i] zawiera teraz liczbe elementow mniejszych lub rownych i
for (i = rozmiar-1; i >= 0; i--)
{
B[(C[(A[i])])-1] = A[i]; // wpisanie do tablicy wynikowej pod okreœlony indeks A[i]
C[(A[i])]--; // zmniejszenie indeksu C[i] - odejmujemy wpisana przed chwila liczbe
}
delete [] C;
}
 
int max_liczba(int tablica[], int rozmiar)
{
int max = tablica[0];
for (int i = 1; i < rozmiar; i++)
{
if (max < tablica[i])
max = tablica[i];
}
return max;
} 
 




int main() {
	int tab[maxSize];
	int wynik[maxSize];
	int z;
	
	scanf("%d", &z);
	for(int i=0; i<z; i++) {
		int size;
		scanf("%d", &size);
		for(int j=0; j<size; j++)
			scanf("%d", &tab[j]);
		//std::cout << "ktore sortowanie? \n 1.bubblesort\n 2.insertionsort\n 3.countingsort\n 4.mergesort\n ";
		int a = rand() % 4;
		//scanf("%d",&a);
		int k = max_liczba(tab, size);
        switch(a)
        {
               case 0: Bubblesort(tab,size);
               break;
               case 1: Insertionsort(size, tab);
               break;
               case 2: countingsort(tab,wynik, k, size);
               break;
               case 3: sortowanie_przez_scalanie(tab,0,size-1);
               break;
               
               default: 
               std::cout << "niepoprawna liczba, wypisywanie bez zmian\n";          
               break;
               }
               
        
		
		if (a==2)
		{
                 for(int l=0;l<size;l++)
                 {
                      printf("%d ", wynik[l]);
		              
                  }
                  printf("\n");
         }
  
  else
  {
        	
	for(int j=0; j<size; j++)
		printf("%d ", tab[j]);
		printf("\n");
  }		
		

	}	
	
    return 0;
}
	


	




// 1 input, 4 outputy ; wzorcowka.out < input > output

