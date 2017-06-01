#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

class Node {
public:

	Node() {
		key = 0;
		value = "";
		height = 1;
		left = right = NULL;
	}

	int key;
	string value;
	int height;
	Node *left, *right;
};

class AVLMap {

public:

	AVLMap() {}
	AVLMap(Node* node) {
		preorderAdd(node);
	}

	void put(int key, string value) {
		root = insert(root, key, value);
	}

	void rem(int key) {
		root = remove(root, key);
	}

	string get(int key) {
		Node* node = root;
		while (true)
		{
			if (node == NULL) return "";
			if (node->key == key) break;
			if (node->key > key) node = node->left;
			else				 node = node->right;
		}
		return node->value;
	}

	void addFromMap(AVLMap map) {
		if (map.root == NULL) return;
		preorderAdd(map.root);
	}

	void addAllSmaller(AVLMap& map, int key) {
		preorderAddSmallerTo(map, key, root);
	}

	void addAllBigger(AVLMap& map, int key) {
		preorderAddBiggerTo(map, key, root);
	}

	void display() {
		cout << "AVLTree (keys) preorder: " << endl;
		preorderDisplay(root);
	}

private:

	Node* root = NULL;

	void preorderDisplay(Node* node) {
		if (node == NULL) return;
		cout << node->key << "=" << node->value << endl;
		preorderDisplay(node->left);
		preorderDisplay(node->right);
	}

	void preorderAdd(Node* node) {
		if (node == NULL) return;
		put(node->key, node->value);
		preorderAdd(node->left);
		preorderAdd(node->right);
	}

	void preorderAddSmallerTo(AVLMap& map, int key, Node* node) {
		if (node == NULL) return;
		if (node->key < key) map.put(node->key, node->value);
		preorderAddSmallerTo(map, key, node->left);
		preorderAddSmallerTo(map, key, node->right);
	}

	void preorderAddBiggerTo(AVLMap& map, int key, Node* node) {
		if (node == NULL) return;
		if (node->key > key) map.put(node->key, node->value);
		preorderAddBiggerTo(map, key, node->left);
		preorderAddBiggerTo(map, key, node->right);
	}

	Node* findeNodeWithKey(int key) {
		Node* node = root;
		while (true)
		{
			if (node == NULL) return NULL;
			if (node->key == key) break;
			if (node->key > key) node = node->left;
			else				 node = node->right;
		}
		return node;
	}

	Node* findMinNode(Node* node) {
		return node->left ? findMinNode(node->left) : node;
	}

	Node* removemin(Node* p)
	{
		if (p->left == 0) return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}

	Node* remove(Node* p, int k) {
		if (!p) return 0;
		if (k < p->key)		 p->left = remove(p->left, k);
		else if (k > p->key) p->right = remove(p->right, k);
		else
		{
			Node* q = p->left;
			Node* r = p->right;
			delete p;
			if (!r) return q;
			Node* min = findMinNode(r);
			min->right = removemin(r);
			min->left = q;
			return balance(min);
		}
		return balance(p);
	}

	Node* insert(Node* node, int key, string value) {
		if (node == NULL) {
			Node* newNode = new Node;
			newNode->key = key;
			newNode->value = value;
			newNode->height = 1;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
		}

		if (node->key > key) node->left = insert(node->left, key, value);
		else				 node->right = insert(node->right, key, value);

		return balance(node);
	}

	int nodeHeight(Node* node) {
		if (node == NULL) return 0;
		else return node->height;
	}

	int getBalanceFactor(Node* node) {
		if (node == NULL) return 0;
		return nodeHeight(node->right) - nodeHeight(node->left);
	}

	void fixNodeHeight(Node* node) {
		int leftNodeHeight = nodeHeight(node->left);
		int rightNodeHeight = nodeHeight(node->right);
		node->height = (leftNodeHeight > rightNodeHeight ? leftNodeHeight : rightNodeHeight) + 1;
	}

	Node* rotateright(Node* p) {
		Node* q = p->left;
		p->left = q->right;
		q->right = p;
		fixNodeHeight(p);
		fixNodeHeight(q);
		return q;
	}

	Node* rotateleft(Node* q) {
		Node* p = q->right;
		q->right = p->left;
		p->left = q;
		fixNodeHeight(q);
		fixNodeHeight(p);
		return p;
	}

	Node* balance(Node* p) {
		fixNodeHeight(p);
		if (getBalanceFactor(p) == 2) {
			if (getBalanceFactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}

		if (getBalanceFactor(p) == -2) {
			if (getBalanceFactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p;
	}

};

void Insert(AVLMap& S, int x, string value) {
	S.put(x, value);
}

void Delete(AVLMap& S, int x) {
	S.rem(x);
}

string Find(AVLMap& S, int x) {
	return S.get(x);
}

AVLMap Join(AVLMap& s1, AVLMap& s2) {
	AVLMap res;
	res.addFromMap(s1);
	res.addFromMap(s2);
	res.display();
	return res;
}

void Split(AVLMap& S, int x) {
	AVLMap leftMap;
	AVLMap rightMap;
	S.addAllSmaller(leftMap, x);
	S.addAllBigger(rightMap, x);
	leftMap.display();
	rightMap.display();
}

int main() {

	AVLMap tree;
	AVLMap leftMap;
	AVLMap rightMap;

	string command, value, treeName, treeName2;
	int key;
	while (true) {
		cin >> command;
		if (command == "insert") { // format: insert <nazwa_drzewa [main|left|right]> <key> <value>
			cin >> treeName >> key >> value;
			if (treeName == "main") Insert(tree, key, value);
			else if (treeName == "left") Insert(leftMap, key, value);
			else if (treeName == "right") Insert(rightMap, key, value);
		}
		else if (command == "delete") { // format: delete <nazwa_drzewa [main|left|right]> <key>
			cin >> treeName >> key;
			if (treeName == "main") Delete(tree, key);
			else if (treeName == "left") Delete(leftMap, key);
			else if (treeName == "right") Delete(rightMap, key);
		}
		else if (command == "find") {
			string foundValue;
			cin >> treeName >> key;
			if (treeName == "main") foundValue = Find(tree, key);
			else if (treeName == "left") foundValue = Find(leftMap, key);
			else if (treeName == "right") foundValue = Find(rightMap, key);
			cout << "found: \"" << foundValue << "\"" << endl;
		}
		else if (command == "join") { // format: join
									  //Join(s1, s2);







			cin >> treeName >> treeName2;
			if (treeName == "main" && treeName2 == "left") Join(tree, leftMap);
			else if (treeName == "main" && treeName2 == "right") Join(tree, rightMap);
			else if (treeName == "left" && treeName2 == "main") Join(leftMap, tree);
			else if (treeName == "right" && treeName2 == "main") Join(rightMap, tree);
			else if (treeName == "left" && treeName2 == "right") Join(leftMap, rightMap);
			else if (treeName == "right" && treeName2 == "left") Join(rightMap, leftMap);






			//tree=Join(leftMap, rightMap);

		}
		else if (command == "split") { // format: split <key>

			cin >> treeName >> key;
			if (treeName == "main") Split(tree, key);
			else if (treeName == "left") Split(leftMap, key);
			else if (treeName == "right") Split(rightMap, key);

			//cin >> key;
			//Split(tree, key); // split wyœwietla oba drzewa
		}
		else if (command == "display") {

			tree.display();
			cout << endl;

		}
		else break;
	}

	return 0;
}
