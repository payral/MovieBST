//Peter Ayral
#include "utility.h"


void Search(StrBST bstmovies, vector<Movie> &vmovies)
{
	for(int i = 0; i<vmovies.size(); i++){
		bstmovies.searchForNode(vmovies[i]);
	}
  	
    
}
void reportStats(vector<double> &times){
	double max= times[0];
	double min= times[0];
	double sum= 0;
	int size = times.size();
	for (int i = 0; i<size; i++){
		if(times[i]<min){
			min=times[i];
		}
		if(times[i]>max){
			max=times[i];
		}
		sum+=times[i];
	}
	double avg = sum/size;
	cout<<"Min: "<<min<< " Max: " << max << " Average: "<< avg<< " miliseconds." << endl;
}