pa4: pa4.o hash.o movie.o
	g++ -o pa4 pa4.o hash.o movie.o
pa4.o: pa4.cpp
	g++ -c -pedantic -Wall -Werror pa4.cpp
hash.o: hash.cpp
	g++ -c -pedantic -Wall -Werror hash.cpp 
movie.o: movie.cpp
	g++ -c -pedantic -Wall -Werror movie.cpp
clean:
	rm *.o