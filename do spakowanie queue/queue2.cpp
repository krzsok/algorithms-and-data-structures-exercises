#include <iostream>
using namespace std;

typedef int elementtype;
typedef struct celltype
{
 elementtype element;
 celltype * next;
};
typedef celltype * position;
class Queue
{
protected:
 position Front; // wskaŸnik do g³owy listy
 position Rear; // wskaŸnik do ostatniego elementu
public:
 Queue(); //konstruktor
~Queue(); //destruktor
void Enqueue(elementtype x);
void Dequeue();
elementtype FrontElem();
bool Empty();
};

// Zainicjuj kolejkê
Queue::Queue(void)
{
 Front = new celltype;
 Rear=Front;
 Front->next=NULL;
}


//wprowadza nowy element
void Queue::Enqueue(elementtype x)
{
 position p=new celltype;
 p->element = x;
 p->next=NULL;
 Rear->next= p;
 Rear=p;
}

// Usuñ pierszy element z kolejki.
void Queue ::Dequeue()
{
 if (!Empty())
 {
 position p=Front;
 Front=Front->next;
 delete p;
 }
}


// Zwróæ pierwszy element z kolejki.
elementtype Queue::FrontElem()
{

 if (!Empty())
 return Front->next->element;
}
// SprawdŸ, czy kolejka jest pusta
bool Queue::Empty()
{
 return (Front->next==NULL);
}

//destruktor
Queue::~Queue(void)
{
 position tmp;

 while (Front->next!=NULL)
 {
 tmp=Front;
 Front=Front->next;
 delete tmp;
 }
delete Front;
}


int main()
{

 Queue Q = Queue();
 
 /*
Q.Enqueue(1);

int a = Q.FrontElem();
cout << a;
Q.Enqueue(2);
cout << Q.FrontElem();
Q.Enqueue(3);
cout << Q.FrontElem();
Q.Enqueue(5);

a = Q.FrontElem();
cout << a;
Q.Enqueue(0);
a = Q.FrontElem();
cout << a;
Q.Enqueue(8);
a = Q.FrontElem();
cout << a;
cout << Q.FrontElem();

*/

string command;
	int i;
	while (true) {
		cin >> command;
		if (command == "enqueue") { 
			cin >> i;
			Q.Enqueue(i);
			
		}
		else if (command == "makenull") { 
             
            Q.~Queue();
			
		}
		else if (command == "dequeue") {
             
			Q.Dequeue();
		
		}
		else if (command == "frontelem") { 
              
             
			int front =Q.FrontElem();
			cout << "Element z przodu: " << front << endl;
			
    

		}
		else if (command == "isempty") { 

		cout << Q.Empty() << endl;
	
        }
    	
		else break;
	}






return 0;
}
