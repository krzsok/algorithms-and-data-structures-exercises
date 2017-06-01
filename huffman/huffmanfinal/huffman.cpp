#include <queue>
#include <stack>
#include<iostream>
#include<vector>

using namespace std;

typedef vector<struct Node> BinaryTree;

struct Node
{
    char symbol;
    unsigned int frequency;
    BinaryTree left;
    BinaryTree right;
};

struct BinaryTreeComparator
{
   bool operator()(const BinaryTree &treeleft, const BinaryTree &treeright)
    {
        Node left = treeleft.front();
        Node right = treeright.front();
        if( left.frequency > right.frequency ) return true; else return false;
    }
};

void huffman(priority_queue<BinaryTree, vector<BinaryTree>, BinaryTreeComparator> &queue)
{
    while(queue.size() > 1)
    {
      BinaryTree b1 = queue.top();
      queue.pop();
      BinaryTree b2 = queue.top();
      queue.pop();
      BinaryTree b3;
      Node n1 = {0, b1.front().frequency + b2.front().frequency, b1, b2};
      b3.push_back(n1);
      queue.push(b3);
    }
}

vector<char> path;

void preorder(BinaryTree tree) 
{
     if(tree.size() == 0) return;
     if(tree.front().symbol != 0)
     {
       for(vector<char>::iterator iter = path.begin(); iter != path.end(); ++iter)
       {
        cout << *iter;
       } 
       cout << ":" << tree.front().symbol << ":" << tree.front().frequency << endl;
     }
     
     path.push_back('0');
     preorder(tree.front().left);
     path.pop_back();
     
     path.push_back('1');
     preorder(tree.front().right);
     path.pop_back();
}

int main() {
	
	int frequency[26]={};
	char alphabet[26]={};
	
	int lettercount=0;
	int wordcount=0;
	
	cin >> lettercount >> wordcount;
	
	char word[lettercount + 1];
	word[lettercount] = 0x00;
	
	cout << wordcount << lettercount << endl;
	
	for(int j=0; j < wordcount; j++)
	{   
        priority_queue<BinaryTree, vector<BinaryTree>, BinaryTreeComparator> queue;
        
        for(int i=0; i < lettercount;i++)
        {
         cin >> word[i];
        }
        
        for(int i=0;i<26;i++)
        {
         int a;
         cin >> a;
         if(a == 0) continue;
         BinaryTree b1, b2, b3;
         
         Node n1 = {i + 'A', a, b2, b3};
         b1.push_back(n1);
         queue.push(b1);       
        }
        
        huffman(queue);
        cout << word << endl;
        preorder(queue.top());
    }
 
	return 0;
}
