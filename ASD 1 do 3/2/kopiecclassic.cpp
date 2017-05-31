/* 
 * File:   main.cpp
 * Author: sokol_1089292
 *
 * Created on 14 marca 2017, 18:09
 */

#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int T[50];
int n;
int m;

int indeksOjca (int i)
{
return floor(i/2);
}

int indeksLewegoSyna (int i)
{
return 2*i;  
}

int indeksPrawegoSyna (int i)
{
return 2*i+1;  
}


int PrzywrocWlasnoscKopca(int i)
{
    
int temp;
int temp2;
int max;    
int lewy = indeksLewegoSyna(i);  
int prawy = indeksPrawegoSyna(i);  
if (lewy <= n-1 && T[i] < T[lewy])
{
  max=lewy;
} 
else
{
  max = i;
}
if (prawy <= n-1 && T[max] < T[prawy])
{
  max=prawy;
}
if (max != i) 
{  
    //zamień miejscami elementy S.T[i] oraz S.T[max]
    temp=T[i];
    temp2=T[max];
    T[max]=temp;
    T[i]=temp2;
    
    i=max;  
    PrzywrocWlasnoscKopca(i);    // rekurencyjne wywołanie  
}  
}
 
int PrzywrocWlasnoscKopca2(int i)
{
    
int temp;
int temp2;
int max;    
int lewy = indeksLewegoSyna(i);  
int prawy = indeksPrawegoSyna(i);  
if (lewy <= m-1 && T[i] < T[lewy])
{
  max=lewy;
} 
else
{
  max = i;
}
if (prawy <= m-1 && T[max] < T[prawy])
{
  max=prawy;
}
if (max != i) 
{  
    //zamień miejscami elementy S.T[i] oraz S.T[max]
    temp=T[i];
    temp2=T[max];
    T[max]=temp;
    T[i]=temp2;
    
    i=max;  
    PrzywrocWlasnoscKopca2(i);    // rekurencyjne wywołanie  
}  
}



int BudujKopiec()
{

// n – rozmiar tablicy T  
  
for (int i=floor(n/2) ; i>=0; i--)  // dzielenie całkowite n/2  
    PrzywrocWlasnoscKopca(i);  
}

int PobierzNajwiekszy()
{
cout << "najwiekszy element : " << T[0] << endl;

int najwiekszy = T[0];


T[0] = T[n-1];   // przesuń „ostatni” liść na miejsce pobranego korzenia  
n--;
PrzywrocWlasnoscKopca(0);

   
return  najwiekszy; 
}

int WypiszKopiec()
{
cout << "gotowy kopiec ";
 
 for(int i = 0; i < n; i++)
    {
        cout << T[i] << " ";
        
    }

cout << endl;
}

int WypiszKopiec2()
{
cout << "gotowy kopiec ";
 
 for(int i = 0; i < m; i++)
    {
        cout << T[i] << " ";
        
    }


cout << endl;
}

int WstawElement()
{


int x;
int temp;
int temp2;

cout << "podaj element : " ;
cin >> x;

n++;  
int i = n - 1; 
T[i]=x; 
while (i>0 && x>T[indeksOjca(i)])
{  
   // zamień T[i] z elementem T[indeksOjca(i)] 
     
    temp=T[i];
    temp2=T[indeksOjca(i)];
    T[indeksOjca(i)]=temp;
    T[i]=temp2;


    i=indeksOjca(i); 
}  
}

int HeapSort()
{

BudujKopiec();


int temp;
int temp2;
//m--;

for (int i=n-1; i>=1; i--)
{  
    
    

    temp = T[0];
    temp2 = T[i];
    T[0] = temp2;
    T[i] = temp;

    m--;

    PrzywrocWlasnoscKopca2(0);


    
}  
}

int HeappSort()
{
    for(int i = 0; i<n; i++)
        {
          PobierzNajwiekszy();  
        }            
}

int Control()
{

 char swtch; 
 cout << "A - wypisanie kopca ; B - Pobranie najwiekszego  ; C - Wstaw element ; D - HeapSort ; E - wyjdz";
 cin >> swtch;
 

 
  switch( swtch )
{
case 'A':
    WypiszKopiec();
    break;

case 'Q':
    WypiszKopiec2();
    break;
    
case 'B':
    PobierzNajwiekszy();
    break;
    
    
case 'C':
    WstawElement();
    break;

case 'D':
    HeapSort();
    break;

case 'E':
    exit(0);
    break;
    
default:
    cout << "niepoprawny parametr" << endl;
    break;
}
}



int main(int argc, char** argv) {
    
    
 cout << "how many elements in A?";
 cin >> n;
m=n;
 cout << "enter A elements"; 

 for(int i = 0; i < n; i++)
    {
        cin >> T[i];
        
    }
 
BudujKopiec();

while(1)
{
Control();
}
    return 0;
}
