using namespace std;

#include<iostream>


void robhuffmana(char[],int[])
{
     
     cout << "robie";
     
 }

int main() {
	
	int frequency[26]={};
	char alphabet[26]={};
	
	int lettercount;
	int wordcount;
	
	cin >> wordcount >> lettercount;
	char chars[wordcount*lettercount];
	cout << wordcount << lettercount;
	
	for(int j=0; j<(wordcount*lettercount); j++)
	{
            
            cin >> chars[j];
                    
    }       
    
		
		for(int j=0; j<26; j++)
	{
        cin >> frequency[j];
        
    }
        
    robhuffmana(chars,frequency);
        
	    
  /*
  
    for( int j=0; j<(wordcount*lettercount); j++)
    {
         cout << chars[j] <<endl;
         
         
     }
	
	 for( int j=0; j<26; j++)
    {
         cout << frequency[j] <<endl;
         
         
     }

	*/
	
	system("pause");
	return 0;
}
