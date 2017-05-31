/* 
 * File:   main.cpp
 * Author: sokol_1089292
 *
 * Created on 28 lutego 2017, 18:12
 */

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>


using namespace std;






int printIntersection(int arr1[], int arr2[], int numA, int numB, vector<int> v, vector<int>::iterator it)
{
  sort (arr1,arr1+numA);    
  sort (arr2,arr2+numB); 
  it=set_intersection (arr1, arr1+numA, arr2, arr2+numB, v.begin());
  v.resize(it-v.begin());

for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;

}



int printUnion(int arr1[], int arr2[], int numA, int numB, vector<int> v, vector<int>::iterator it)
{
  
  sort (arr1,arr1+numA);    
  sort (arr2,arr2+numB); 
  it=set_union (arr1, arr1+numA, arr2, arr2+numB, v.begin());
  v.resize(it-v.begin());

for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;
  

}



int printDifference(int arr1[], int arr2[], int numA, int numB, vector<int> v, vector<int>::iterator it)
{
  sort (arr1,arr1+numA);    
  sort (arr2,arr2+numB); 
  it=set_difference (arr1, arr1+numA, arr2, arr2+numB, v.begin());
  v.resize(it-v.begin());

for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;
   
    
}

int printSymDifference(int arr1[], int arr2[], int numA, int numB, vector<int> v, vector<int>::iterator it)
{
  sort (arr1,arr1+numA);    
  sort (arr2,arr2+numB); 
  it=set_symmetric_difference (arr1, arr1+numA, arr2, arr2+numB, v.begin());
  v.resize(it-v.begin());

for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;
   
    
}



int main()
{

 int arr1[50];
 int arr2[50];
 int numA;
 int numB;
 vector<int> v(100);                      
 vector<int>::iterator it;
 
 cout << "how many elements in A?";
 cin >> numA;
 cout << "enter A elements"; 

 for(int i = 0; i < numA; i++)
    {
        cin >> arr1[i];
        
    }
    
 cout << "how many elements in B?";
 cin >> numB;
 cout << "enter B elements"; 

 for(int i = 0; i < numB; i++)
    {
        cin >> arr2[i];
        
    }
 char swtch; 
 cout << "write A for sum, B for intersection, C for difference, D for symmetrical difference";
 cin >> swtch;
 
 
  switch( swtch )
{
case 'A':
    printUnion(arr1, arr2, numA, numB, v, it);
    break;
    
case 'B':
    printIntersection(arr1, arr2, numA, numB, v, it);
    break;
    
    
case 'C':
    printDifference(arr1, arr2, numA, numB, v, it);
    break;

case 'D':
    printSymDifference(arr1, arr2, numA, numB, v, it);
    break;
    
default:
    cout << "niepoprawny parametr";
    break;
}
 
  
  getchar();
  return 0;
}
