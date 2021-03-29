//Peter Ayral
//add depth functionality

#include "movies.h"

Movie::Movie(){
	name = "";
	rating= 0.0;
}

Movie::Movie(string n, double r){
	name = n;
	rating = r;
}
//default constructor
StrBST::StrBST(){
	root = NULL;
	highest = 0.0;
	best= NULL;
}
StrBST::~StrBST(){
	clear(root);
}
void StrBST::clear(Node *n){
	if (n){
		clear(n->left);
		clear(n->right);
		delete n;
	}
}



void StrBST::insert(Movie m){
	// handle special case of empty tree first
    if (!root) {
	root = new Node(m);
	N_visited.push_back(0);
	N.push_back(0);
	return;
    }
    // otherwise use recursive helper
    insert(m, root,1);
}

void StrBST::insert(Movie m, Node *n, int n_vis) {
    if (m.getName() < n->mov.getName()) {
		if (n->left)
	    	insert(m, n->left,n_vis+1);
		else {
	    	n->left = new Node(m);
	    	n->left->parent = n;
	    	N_visited.push_back(n_vis);
	    	return;
		}
    }
    else {
		if (n->right)
	    	insert(m, n->right,n_vis+1);
		else {
	    	n->right = new Node(m);
	    	n->right->parent = n;
	    	N_visited.push_back(n_vis);
	    	return;
		}
    }
}
void StrBST::printPreOrder() {
    printPreOrder(root);
}

void StrBST::printPreOrder(Node *n){
	if (n){
		cout<< n->mov.getName()<< ", "<<n->mov.getRating() <<", " << getDepth(n->mov) <<endl;
		printPreOrder(n->left);
		printPreOrder(n->right);
	}
}

int StrBST::getDepth(Movie m){
	Node *n;
	int count = 0;
	n=getNodeFor(m,root);
	while(n->parent){
		count++;
		n=n->parent;
	}
	return count;
}

void StrBST::searchForNode(Movie m) {
	getNodeFor(m, root);
}

StrBST::Node* StrBST::getNodeFor(Movie m, Node* n) const{
     if (n == nullptr){
     	return NULL;
     }
     if (n->mov.getName()==m.getName()){
     	return n;
     }
     if (n->mov.getName()<m.getName()){
     	return getNodeFor(m,n->right);
     }
     else {// n>movie 
     	return getNodeFor(m,n->left);
     }
     return NULL;
}

void StrBST::findHighest(string str){
	Node *high;
	findHighest(str,root,best);
	if(best!=nullptr){
	cout<<"Best movie is "<< best->mov.getName() << " with rating " << best->mov.getRating()<<endl;}
}

void StrBST::findHighest(string str, Node* n, Node* x){//if it ain't broke don't fix it
	if(n==nullptr){
		return;
	}
	int lenstr= str.size();
	string sub = n->mov.getName().substr(0,lenstr);
	if(sub.find(str) != string::npos){
		if (n->mov.getRating()>highest)
		{
			highest=n->mov.getRating();
			best= n;
		}
	}
	if(n){
		findHighest(str, n->left, best);
		findHighest(str, n->right, best);
	}
}

void StrBST::setN(){
	int count=1;
	for(int i = 0; i<N_visited.size(); i++){
		N.push_back(count);
		count++;
	}
}