//Peter Ayral


#ifndef StrBST_H
#define StrBST_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie{
public:
	Movie();
	Movie(string n, double r);
	string getName() {return name;}
	double getRating() {return rating;}
	
private:
	string name;
	double rating;
	
};

class StrBST{
public:
	StrBST();
	~StrBST();
	void insert(Movie m);
	void printPreOrder();
	int getDepth(Movie m);
	void findHighest(string str);
	double highest;
	void searchForNode(Movie m);
	vector<int> N_visited;
	vector<int> N;
	void setN();

private:
	struct Node{
		Movie mov;
		Node *left, *right, *parent;
	Node(Movie x) : mov(x), left(NULL), right(NULL), parent(NULL) { }
	};
	Node *root;
	Node *best;
	Node* getNodeFor(Movie m, Node* n) const;
	void insert(Movie m, Node *n, int n_vis);
	void printPreOrder(Node *n);
	void clear(Node *n); //for destructor
	void findHighest(string str, Node* n, Node* x);

};

#endif