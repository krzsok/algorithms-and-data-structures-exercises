/* 
 * File:   main.cpp
 * Author: sokol_1089292
 *
 * Created on 28 marca 2017, 19:10
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <queue>





using namespace std;

int n,m,u,v1,v2,s,e;

int col[50]; // 0 - bialy, 1 - szary, 2 - czarny
int dst[50];
int prn[50];
vector<int> adj[50];
queue <int> Q;
vector<int>::iterator v;






int BFS(int s)
{
    
    for(int i=0; i<n; i++)
    {
        col[i]=0;
        dst[i]=99;
        prn[i]=33;
        
    }
    
    col[s] = 1;
    dst[s] = 99;
    prn[s] = 33;
    
    Q.push(s);
    while(Q.empty() != 1)
    {
        //pobrac liste sasiedztwa dla u
        u = Q.front();
        Q.pop();
        for(v = adj[u].begin(); v != adj[u].end(); ++v )
        {
            if(col[*v] == 0)
            {
                cout << *v <<endl;
                col[*v] = 1;
                dst[*v] = dst[u] + 1;
                prn[*v] = u; 
               Q.push(*v);
                
            }
        }
        
        col[u] = 2;
    }
    
    
    
    
    
    
    
    
    /*
     
     dla każdego wierzchołka u z G:
        kolor[u] = biały
        odleglosc[u] = inf
        rodzic[u] = NIL
    kolor[s] = SZARY
    odleglosc[s] = 0
    rodzic[s] = NIL
    Q.push(s)
    dopóki kolejka Q nie jest pusta:
        u = Q.pop()
        dla każdego v z listy sąsiedztwa u:
            jeżeli v jest biały:
                kolor[v] = SZARY
                odleglosc[v] = odleglosc[u] + 1
                rodzic[v] = u
                Q.push(v)
        kolor[u] = CZARNY

     
     */
}

/*
 * 
 */
int main(int argc, char** argv) {

 
  cout << "podaj liczbe wierzcholkow i krawedzi : " << endl;
  cin >> n >> m;         // liczba wierzcholkow i krawedzi
  int T[n][n];
  
  
  
  

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) T[i][j] = 0;

  // ^zerowanie

  cout << "podaj wierzcholek poczatkowy i koncowy krawedzi(wierzcholki liczone od 0)" << endl;
  for(int i = 0; i < m; i++)
  {
    cin >> v1 >> v2;    
    T[v1][v2] = 1;
    T[v2][v1] = 1;// krawedz v1->v2, v2->v1 obecna
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  
  // lista
  
  cout << "lista sasiedztwa : " << endl;
  for(int r=0; r<n; r++)
  {
   cout << r << ": ";
   copy(adj[r].begin(),adj[r].end(),ostream_iterator<int>(std::cout<< " " ));
   cout << endl;
  }

  cout << endl;
  
  cout << "podaj wierzchołek początkowy i końcowy przeszukiwania:" << endl;
  
  cin >> s >> e;
  
  BFS(s);
  
  int z;
  int counter = 0;
  z = e;
 
   cout << "dlugoscalt:" << dst[z] - dst[s] << endl;
  
  cout << "droga: " << endl;
  cout << z;
  cout << endl;
  do
  {

      
      
      cout << prn[z] << endl;
      z = prn[z];
      counter++;
              
      
  } while(prn[z] != 33); 
  
  cout << "dlugosc : " << counter;
  
 
  
  
  
  

  return 0;
}
