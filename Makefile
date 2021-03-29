all: runMovies tests
runMovies: movies.cpp utility.cpp main.cpp
	g++ -g movies.h utility.h movies.cpp utility.cpp main.cpp -o runMovies
tests: movies.cpp utility.cpp tests.cpp
	g++ -g movies.h movies.cpp utility.h utility.cpp tests.h tests.cpp -o tests
	./tests;
clean:
	rm -f tets runMovies *.o