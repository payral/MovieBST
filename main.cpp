#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"
#include "utility.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << " arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an object of the BST class you defined 
  // to contain the name and rating in the input file
  StrBST movielist;
  vector<Movie> vmovies;
  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    // Use std::string movieName and double movieRating
    // to construct your Movie objects
    Movie temp(movieName,movieRating);
    vmovies.push_back(temp);
    movielist.insert(temp);

    //cout << movieName << " has rating " << movieRating << endl;

  }
  movieFile.close();


 if (flag){
 	movielist.printPreOrder();
 	cout<<endl;
    movielist.findHighest(argv[3]); }

 if (flag==false)
 {
 	int count=0;
 	vector<double> times;
 	for(int i = 0; i< stoi(argv[3]); i++){
 		clock_t time_before = clock();
 		for(int i = 0; i<vmovies.size(); i++){
		movielist.searchForNode(vmovies[i]);
		}
		clock_t time_after = clock();
		times.push_back((time_after - time_before)/static_cast<double>(CLOCKS_PER_SEC)*1000);
		//cout<<(time_after - time_before)/static_cast<double>(CLOCKS_PER_SEC)*1000<<endl;
	}
	reportStats(times);
	//movielist.setN();
	/*ofstream nput; 
	nput.open("output.csv");
	for(int i = 0; i<vmovies.size(); i++){
		nput<< movielist.N[i]<< "," << movielist.N_visited[i]<<endl;
	}
	nput.close();*/
    //cout << "This took  " << (time_after - time_before)/static_cast<double>(CLOCKS_PER_SEC) << " seconds.\n";
	//cout << "The average time to search for a node is " << (time_after - time_before)/(vmovies.size()*stoi(argv[3])*static_cast<double>(CLOCKS_PER_SEC)) << " seconds."<< endl;
  }



return 0;
}




bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

