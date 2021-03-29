//Peter Ayral

#include "tests.h"


int main(){
	runAll();
	//test_BST();
	return 0;
}

void runAll(){
	test_emptymovie();
	test_movie();
}

void test_emptymovie(){
	Movie c;
	assertEquals("", c.getName(), "Default movie");
	assertEquals(0.0, c.getRating(), "Default rating");
}
void test_movie(){
	Movie c("Django",9.0);
	assertEquals("Django",c.getName(), "Movie constructor");
	assertEquals(9.0,c.getRating(), "Movie constructor rating");
}
void test_BST(){
	StrBST mlist;
	Movie d("KillBill",8.7);
	Movie o("OnceUpon", 8.6);
	Movie i("Inglorious", 8.8);
	cout<<(d.getName()<o.getName())<<endl;
	mlist.insert(d);
	mlist.insert(o);
	mlist.insert(i);
	mlist.printPreOrder();
}

void test_Depth(){
	StrBST mlist;
	Movie d("KillBill",8.7);
	Movie o("OnceUpon", 8.6);
	Movie i("Inglorious", 8.8);
	cout<<(d.getName()<o.getName())<<endl;
	mlist.insert(d);
	mlist.insert(o);
	mlist.insert(i);
	mlist.printPreOrder();
}