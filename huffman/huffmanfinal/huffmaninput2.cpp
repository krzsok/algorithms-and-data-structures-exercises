using namespace std;

#include<iostream>







int main() {
	//char tab[lettercount];
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int frequency[26]={};
	
    //for(int i=0; i<28; i++)
    //cout << alphabet[i] << endl;
	srand (time(NULL));
	
	int lettercount = rand() % 9 + 9;
	int wordcount = rand() % 9 + 1;
	
	cout << lettercount << endl <<wordcount;
	
	for(int j=0; j<wordcount; j++)
	{
            
            cout << endl;
            
	        for(int i=0; i<lettercount; i++) 
	        {
                int c = rand() % 26;
                cout << alphabet[c];
                frequency[c]++;
                
            }
            
            for(int i=0;i<26;i++)
            {
                    
            cout << endl << frequency[i];
            frequency[i]=0;
            }
    }       
    
    cout << endl;
		
	return 0;
}
