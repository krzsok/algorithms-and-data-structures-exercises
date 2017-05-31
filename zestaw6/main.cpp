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
#include <algorithm>
#include <list>





using namespace std;

int n,m,v1,v2;
int tme;
int ccounter = 0;

int col[50]; // 0 - bialy, 1 - szary, 2 - czarny
int prn[50];
int d[50] = {};
int f[50] = {};
vector<int> adj[50];
list<int> ts;
list<int> ts2;
//int zet, ygrek;
//int OG[50];
//int edge[50]; //0 - tree(unvisited), 1-visited(forward), 2-explored(back)
//int counter2 = 0;



//vector<int>::iterator v;
//int v;
/*function VisitNode(u):
       oznacz u jako odwiedzony
       dla każdego wierzchołka v na liście sąsiedztwa u:
           jeżeli v nieodwiedzony:
               VisitNode(v)
   function DepthFirstSearch(Graf G):
       dla każdego wierzchołka u z grafu G:
           oznacz u jako nieodwiedzony
       dla każdego wierzchołka u z grafu G:
           jeżeli u nieodwiedzony:
               VisitNode(u) */

//DFS(u)
//for each neighbor v of u
//  if v is unvisited, tree edge, DFS(v)
//  else if v is explored, bidirectional/back edge
//  else if v is visited, forward/cross edge

int Cycles(int u)
{
        cout << "cykle:" << endl;

//     for(int ii = 0; ii < counter2; ii++)
//    {
//        
//      int zet = OG[ii];
//      int ygrek = OG[ii];
      int k = u;
      
    do
  {

      
//      
//      cout << prn[zet] << endl;
//      zet = prn[zet];
//      //counter++;
        
        cout << prn[u] << endl;
        u = prn[u];
        
              
      
  }while(prn[u] != k); 
    
}
//}


int VisitNode(int u)
{
    tme = tme + 1;
    d[u] = tme;
  
    
  
  //for(v = adj[u].begin; v != adj[u].end(); ++v )
  // for_each(adj[u].begin(),adj[u].end(),vn)
    //while(v != adj[u].end)
    //for ( auto &i : v )  
   // for(v = adj[u].front(); v != adj[u].back(); ++v )
//  for(v = adj[u][0]; v < adj[u].size(); v++)
//  {
//      
//    if(col[v] == 0)
//    {
//        
//         prn[v] = u; 
//         int g = v;
//         VisitNode(g);
//    }
//               
//                
//        }
//    
//    if(col[v] == 0)
//    {
//       
//    col[u] = 2;
//    tme = tme + 1;
//    f[u] = tme;
//    
//}
    
    
    
    
    
     for(vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++)
  {
     
    if(col[*v] == 0)
    {
        //cout << "parent" << *v << "=" << u << endl;
         prn[*v] = u; 
         // cout << "parent" << *v << "=" << u << endl;
         int g = *v;
         col[u] = 1;
        cout << "od wierzcholka " << u << " do  wierzcholka " << *v << " TREE EDGE" << endl;

         VisitNode(g);
    }
    
    else if(col[*v] == 1)
    {
        prn[*v] = u;
        col[u] = 2;
        cout << "od wierzcholka " << u << " do  wierzcholka " << *v << " BACK EDGE" << endl;
       // OG[counter2] = *v;
       // counter2++;
       // Cycles(*v);
        ccounter++;
    }
      
    else if(col[*v] == 2)
    {
        prn[*v] = u;
                cout << "od wierzcholka " << u << " do  wierzcholka " << *v << " CROSS/FORWARD EDGE" << endl;

    }
                
        }
    

    col[u] = 2; //black
    tme = tme + 1;
    f[u] = tme;
    ts.push_front(u);
    ts2.push_front(tme);
    
    
    
    
    
    
    
    
}
int DFS(int u)
{
    for(int i=0; i<n; i++)
    {
        col[i]=0;
        prn[i]=33;
        
    }
  
    tme = 0;
  
    for(int i=0; i<n; i++)
    {
       
       if(col[i]==0)
        {
           VisitNode(i); 
        }
          
    }
    
      
   
}


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
    //T[v2][v1] = 1;// krawedz v1->v2, v2->v1 obecna
    adj[v1].push_back(v2);
    //adj[v2].push_back(v1);
  }

  
  // lista
//  
//  cout << "lista sasiedztwa : " << endl;
//  for(int r=0; r<n; r++)
//  {
//   cout << r << ": ";
//   copy(adj[r].begin(),adj[r].end(),ostream_iterator<int>(std::cout<< " " ));
//   cout << endl;
//  }
//
//  cout << endl;
//  
  
  //macierz sasiedztwa
  
  cout << "macierz sasiedztwa : " << endl;
  
  cout << "   ";
  for(int i = 0; i < n; i++) cout << setw(3) << i;
  cout << endl << endl;
  for(int i = 0; i < n; i++)
  {
    cout << setw(3) << i;
    for(int j = 0; j < n; j++) cout << setw(3) << (int) T[i][j];
    cout << endl;
  }

  
  
  
  DFS(0);
  

  
  
  if(ccounter == 0)
  {
      cout << endl << "GRAF ACYKLICZNY";
      cout << endl << "sortowanie topologiczne - wierzcholki : " << endl;
      
      for(list<int>::iterator it = ts.begin(); it != ts.end(); it++)
      {
          cout << *it << endl;
      }
      
      
      cout << "czasy zakonczenia" << endl;
      
      for(list<int>::iterator it = ts2.begin(); it != ts2.end(); it++)
      {
          cout << *it << endl;
      }
  }
  else 
  {
      cout << endl << "GRAF CYKLICZNY, " << ccounter << " CYKL(E)";
  }

  return 0;
}
