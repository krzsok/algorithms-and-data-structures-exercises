/* 
 * File:   main.cpp
 * Author: sokol_1089292
 *
 * Created on 28 lutego 2017, 18:12
 */

#include<iostream>
#include<stdio.h>


using namespace std;

int arr1[50];
int arr2[50];
int arr3[50];
int numA;
int numB;
int numC = 0;
bool SD;
bool D;

int printIntersection(int arr1[], int arr2[], int arr3[], int m, int n)
{

  if(SD != 1 && D != 1)
  cout << "przeciecie : ";  
  int i = 0, j = 0, k = 0;
  while(i < m && j < n)
  {
    if(arr1[i] < arr2[j])
      i++;
    else if(arr2[j] < arr1[i])
      j++;
    else /* if arr1[i] == arr2[j] */
    {
      if(SD != 1 && D != 1)
      cout<<arr1[i];
      arr3[k]=arr1[i];
      k++;
      numC++;
      i++;
      j++;
    }
  }
  if(SD != 1)
  cout<< endl;
}


int printUnion(int arr1[], int arr2[], int m, int n)
{
  cout << "suma : ";
  int i = 0, j = 0;
  while(i < m && j < n)
  {
    if(arr1[i] < arr2[j])
      cout<<arr1[i++];
    else if(arr2[j] < arr1[i])
      cout<<arr2[j++];
    else
    {
      cout<<arr2[j++];
      i++;
    }
  }

  /* Print remaining elements of the larger array */
  while(i < m)
   cout<<arr1[i++];
  while(j < n)
   cout<<arr2[j++];
}

int printDifference(int arr1[], int arr2[], int arr3[], int m, int n)
{
    D = 1;
    printIntersection(arr1, arr2, arr3, numA, numB);
    
    if(SD != 1)
    cout << "roznica : ";
    
    for(int i = 0;i < numA; i++)
    {
       for(int j = 0; j < numC; j++) 
       {
           if (arr1[i] != arr3[j] && j == (numC-1))
           {
               cout<<arr1[i];
               
           }
               else if(arr1[i] == arr3[j])
                break;
               
               
               
       }
        
            
    }
    
}

int printSymDifference(int arr1[], int arr2[], int arr3[], int m, int n)
{
     // printIntersection(arr1, arr2, arr3, numA, numB);
    SD = 1;
    cout << "roznica symetryczna : ";  
    printDifference(arr1, arr2, arr3, numA, numB);
    printDifference(arr2, arr1, arr3, numB, numA);
    

    
/*    
  for(int i = 0;i < numA; i++)
    {
       for(int j = 0; j < numC; j++) 
       {
           if (arr1[i] != arr3[j] && j == (numC-1))
           {
               cout<<arr1[i];
               
           }
               else if(arr1[i] == arr3[j])
                break;
               
               
               
       }
        
            
    }


    for(int i = 0;i < numB; i++)
    {
       for(int j = 0; j < numC; j++) 
       {
           if (arr2[i] != arr3[j] && j == (numB-1))
           {
               cout<<arr2[i];
               
           }
               else if(arr2[i] == arr3[j])
                break;
               
               
               
       }
        
            
    }
*/    
}



int main()
{
 
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
 
  
  //int m = sizeof(arr1)/sizeof(arr1[0]);
  //int n = sizeof(arr2)/sizeof(arr2[0]);
  switch( swtch )
{
case 'A':
    printUnion(arr1, arr2, numA, numB);
    break;
    
case 'B':
    printIntersection(arr1, arr2, arr3, numA, numB);
    break;
    
    
case 'C':
    printDifference(arr1, arr2, arr3, numA, numB);
    break;

case 'D':
    printSymDifference(arr1, arr2, arr3, numA, numB);
    break;
    
default:
    cout << "niepoprawny parametr";
    break;
}
 
  
  getchar();
  return 0;
}
