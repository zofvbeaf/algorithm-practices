all:
	g++ -g -std=c++11 -o test test.cpp
	g++ -g -std=c++11 -o standard standard.cpp
	g++ -g -std=c++11 -o random random.cpp
	./random > in.txt
	./test < in.txt > test.out
	./standard < in.txt > standard.out	
	diff test.out standard.out
cl:
	rm -f test standard random
