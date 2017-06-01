#include<iostream>
using namespace std;

typedef int elementtype;
typedef struct celltype
{
elementtype element;
celltype * next;
celltype * prev;
};
typedef celltype * position; 

class Lista
{
protected :
position l;//wskaŸnik do pierwszego elementu
public:
Lista();
~Lista();
void Insert(elementtype x, position p);
void Delete(position p);
elementtype Retrieve(position p);
position Locate(elementtype x);
position First();
position Next(position p);
position Previous(position p);
position END();
void printList();
};

Lista::Lista()
{//mamy listê bez g³owy, wiêc konstruktor ustawia l na NULL
l=NULL;
}

void Lista::Insert(elementtype x,position p)
{position tmp;
 if (p==l) //chcemy wstawiæ na pocz¹tek listy
 { l=new celltype;
 l->element=x;
 l->next=p;
 l->prev=NULL;
 if (l->next!=NULL) l->next->prev=l;
 }
 else
 { if (p==NULL)//chcemy wstawiæ na koniec listy-za ostatnim elementem
{tmp=l; while (tmp->next!=NULL) tmp=tmp->next;}
 else tmp=p->prev;
 tmp->next=new celltype;
 tmp->next->element=x;
 tmp->next->next=p;
 tmp->next->prev=tmp;
 if (tmp->next->next!=NULL) tmp->next->next->prev=tmp->next;
 }}// INSERT


void Lista::Delete(position p)
{
if (l!=NULL)
{
if (p->prev!=NULL) p->prev->next=p->next;
if (p->next!=NULL) p->next->prev=p->prev;
if (p==l) l=p->next;
delete p;
}
}//delete


position Lista::Locate(elementtype x)
{
position tmp=l;
while (tmp!=NULL)
{
 if (tmp->element==x) return tmp;
 tmp=tmp->next;
}
 return tmp; //zwraca ENDL, jeœli wczeœniej nie zosta³
 // znaleziony rekord z elementem x}
}//locate 


elementtype Lista::Retrieve(position p)
{
return p->element;
}//retrieve 

position Lista::First()
{
return l;
}

position Lista::Next(position p)
{
return p->next;
}


position Lista::Previous(position p)
{
if (p==NULL) //chcemy zwróciæ wskaŸnik do ostatniej komórki
 {
 position tmp=l;
 while (tmp->next!=NULL) tmp=tmp->next;
 return tmp;
 }
 else
return p->prev; 
 }
 
position Lista::END()
{
return NULL;
}


Lista::~Lista()
{//mamy listê bez g³owy, wiêc destruktor usuwa wszystkie elementy oprócz g³owy

position tmp;
while (l!=NULL)
{
tmp=l;
l=l->next;
delete tmp;
}
}

void Lista::printList()
{
 std::cout <<"lista: " <<endl;

 position tmp;
 tmp=First();
   


 
 do
 {
  std::cout << tmp->element <<endl;
  tmp=Next(tmp);  
               
 }
while(tmp->next!=NULL);

std::cout << tmp->element <<endl;


 
     
}

int main()
{


Lista x=Lista();
celltype* c;
//test insert
x.Insert(1,NULL);
x.Insert(2,NULL);
x.Insert(3,NULL);
x.Insert(7,NULL);
x.Insert(4,NULL);
x.Insert(3,NULL);
x.printList();

//test locate
c=x.Locate(2);
std::cout <<"zlokalizowano: " << c->element <<endl;
std::cout <<" adres next: " << c->next <<endl;
std::cout <<" adres prev: " << c->prev <<endl;

//test delete
x.Delete(x.Locate(3));
cout <<"usunieto element" <<endl;

x.printList();

//test retrieve
int number = x.Retrieve(x.Locate(7));
cout <<"pozyskany numer: " << number <<endl;


//test previous
int previous = x.Retrieve(x.Previous(x.Locate(2)));
cout <<"poprzednik: " << previous <<endl;


//reszta metod to proste gettery




/*

string command;
	int i;
	while (true) {
		cin >> command;
		if (command == "insert") { 
			cin >> i;
			x.Insert(i,NULL);
			
		}
		else if (command == "makenull") { 
             
            x.~Lista();
			
		}
		else if (command == "delete") {
             cin >> i;
			x.Delete(x.Locate(i));
		
		}
		else if (command == "retrieve") { 
              
            cin >> i;
			int element = x.Retrieve(x.Locate(i));
			cout << element << endl;
    

		}
		else if (command == "printlist") { 

			x.printList();

			
		}
		
		else break;
	}


*/

return 0;
}

